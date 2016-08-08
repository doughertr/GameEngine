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
	Profiler profiler;
	const char* profilerFileName = "profiles.csv";
	profiler.init(profilerFileName);

	const unsigned int NUM_ENTRIES = 15;

	for (float i = 0; i < NUM_ENTRIES; i++) {
		profiler.newFrame();
		profiler.addEntry("Category 1", i);
		profiler.addEntry("Category 2", i);
		profiler.addEntry("Category 3", i);
	}
	profiler.shutdown();
	ifstream input(profilerFileName);

	EXPECT_EQ(getNextToken(input), "Category1");
	EXPECT_EQ(getNextToken(input), "Category2");
	EXPECT_EQ(getNextToken(input), "Category3");
	for (unsigned int i = 0; i < NUM_ENTRIES; i++)
	{
		string buffer = getNextToken(input);
		EXPECT_EQ(atoi(buffer.c_str()), i);
	}
}