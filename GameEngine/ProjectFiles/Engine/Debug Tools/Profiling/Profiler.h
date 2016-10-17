#ifndef DEBUG_PROFILER
#define DEBUG_PROFILER

#include <iostream>
using std::string;

class __declspec(dllexport) Profiler
{
	const char* fileName;
	int frameIndex;
	int categoryIndex;
	unsigned int numProfileCategories;

	static const unsigned int MAX_FRAME_SAMPLES = 500;
	static const unsigned int MAX_PROFILE_CATEGORIES = 20;

	struct ProfileCategory
	{
		const char* name;
		float samples[MAX_FRAME_SAMPLES];
	} categories[MAX_PROFILE_CATEGORIES];

	char* getDelimiter(unsigned int index) const;
public:
	bool init(const char* fileName);
	bool shutdown();

	void addEntry(const char* categoryName, float time);
	void newFrame();
};
#endif
