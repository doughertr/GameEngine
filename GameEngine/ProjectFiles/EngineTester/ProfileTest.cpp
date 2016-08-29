#include <gtest\gtest.h>
#include <Debug Tools\Profiling\Profiler.h>
#include <fstream>
using std::ifstream;
using std::string;

string getNextToken(ifstream& file)
{
	char c;
	string ret;
	while (file.good())
	{
		file >> c;
		if (c == ',' || c == '\n')
			break;
		ret += c;
	}
	return ret;
}

TEST(Profiler, TestEntryAddition)
{
	char * categories[] = 
	{
		"Category1",
		"Category2",
		"Category3"
	};

	Profiler profiler;
	const char* profilerFileName = "profiles.csv";
	profiler.init(profilerFileName);

	const unsigned int NUM_CATEGORIES = sizeof(categories) / sizeof(*categories);
	const unsigned int NUM_FRAMES = 5;
	float sampleNum = 0;

	for (float frame = 0; frame < NUM_FRAMES; frame++) {
		profiler.newFrame();
		for (unsigned int cat = 0; cat < NUM_CATEGORIES; cat++)
		{
			profiler.addEntry(categories[cat], sampleNum++);
		}

	}
	profiler.shutdown();
	ifstream input(profilerFileName);
	string buf;

	std::getline(input, buf);

	EXPECT_EQ(buf, string(categories[0]) + "," + string(categories[1]) + "," + string(categories[2]));

}