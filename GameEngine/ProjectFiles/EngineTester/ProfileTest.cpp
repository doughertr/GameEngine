#include <gtest\gtest.h>
#include <Debug Tools\Profiling\Profiler.h>
#include <fstream>
#include "ProfileTest.h"
using std::ifstream;
using std::string;
using std::vector;

//unnamed namespace makes these variables private to this .cpp file only

struct ProfileValues
{
	const char* const PROFILER_FILE_NAME;
	const unsigned int NUM_CATEGORIES;
	const unsigned int NUM_FRAMES;
	char* categories[NUM_CATEGORIES];
};
ProfileValues defualtValues;

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
void writeSamples(const char* const PROFILER_FILE_NAME, char* categories[], const unsigned int NUM_CATEGORIES, const unsigned int NUM_FRAMES)
{


	Profiler profiler;
	profiler.init(PROFILER_FILE_NAME);


	float sampleNum = 0;

	for (float frame = 0; frame < NUM_FRAMES; frame++) {
		profiler.newFrame();
		for (unsigned int cat = 0; cat < NUM_CATEGORIES; cat++)
		{
			profiler.addEntry(categories[cat], sampleNum++);
		}

	}
	profiler.shutdown();
}

TEST(Profiler, TestEntryAddition)
{
	writeSamples(defaultValues);
	ifstream input(PROFILER_FILE_NAME);
	string buf;

	std::getline(input, buf);

	EXPECT_EQ(buf, string(categories[0]) + ",\t" + string(categories[1]) + ",\t" + string(categories[2]));

}
TEST(Profiler, ExcludeIncompleteGameFrames)
{
	writeSamples();
}