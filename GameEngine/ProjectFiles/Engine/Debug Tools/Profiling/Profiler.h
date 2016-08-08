#ifndef DEBUG_PROFILER
#define DEBUG_PROFILER

#include <iostream>
using std::string;

class __declspec(dllexport) Profiler
{
public:
	bool init(const char* filename);
	bool shutdown();

	void addEntry(const char* category, float time);
	void newFrame();
};
#endif
