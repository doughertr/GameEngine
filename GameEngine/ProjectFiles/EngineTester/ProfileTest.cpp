#include <gtest\gtest.h>
#include <Debug Tools\Profiling\Profiler.h>
#include <fstream>
#include "ProfileTest.h"
using std::ifstream;
using std::string;
using std::vector;

//unnamed namespace makes these variables private to this .cpp file only
namespace 
{
	Profiler profiler;
	const char* const PROFILER_FILE_NAME = "profiles.csv";

	char* categories[] = 
	{
		"Category1",
		"Category2",
		"Category3"
	};
	const unsigned int NUM_CATEGORIES = sizeof(categories) / sizeof(*categories);
	const unsigned int NUM_FRAMES = 5;
};

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
void writeSamples()
{
	float sampleNum = 0;

	for (float frame = 0; frame < NUM_FRAMES; frame++) 
	{
		profiler.newFrame();
		for (unsigned int cat = 0; cat < NUM_CATEGORIES; cat++)
		{
			profiler.addEntry(categories[cat], sampleNum++);
		}
	}
}
bool isAtEndOfFile(ifstream& input) 
{
	if (!input.good())
		return false;
	char bitBucket;
	input >> bitBucket;
	return !input.good();
}

void checkSamples()
{
	ifstream input(PROFILER_FILE_NAME);

	EXPECT_EQ(getNextToken(input), "Category1");
	EXPECT_EQ(getNextToken(input), "Category2");
	EXPECT_EQ(getNextToken(input), "Category3");
	for (int i = 0; i < (NUM_CATEGORIES * NUM_CATEGORIES); i++)
	{
		string buf = getNextToken(input);
		EXPECT_EQ(atoi(buf.c_str()), i);
	}
	EXPECT_TRUE(isAtEndOfFile(input));
}
#if false
TEST(Profiler, TestEntryAddition)
{
	profiler.init(PROFILER_FILE_NAME);
	writeSamples();
	profiler.shutdown();
	ifstream input(PROFILER_FILE_NAME);
	string buf;

	std::getline(input, buf);

	EXPECT_EQ(buf, string(categories[0]) + ",\t" + string(categories[1]) + ",\t" + string(categories[2]));

}
#endif
TEST(Profiler, ExcludeIncompleteGameFrames)
{
	profiler.init(PROFILER_FILE_NAME);
	writeSamples();
	profiler.newFrame();
	//checkSamples();
	profiler.addEntry(categories[0], 15);
	profiler.shutdown();
}