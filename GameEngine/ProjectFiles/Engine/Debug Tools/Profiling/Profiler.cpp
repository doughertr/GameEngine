#include "Profiler.h"
#include <cassert>
#include <fstream>
using std::ofstream;
using std::ios;
bool Profiler::init(const char* fileName)
{
	this->fileName = fileName;
	this->frameIndex = -1;
	this->categoryIndex = 0;
	this->numProfileCategories = 0;
	return false;
}
bool Profiler::shutdown()
{
	ofstream outStream(fileName, ios::trunc);
	//writing category headers
	for (unsigned int i = 0; i < numProfileCategories; i++)
	{
		outStream << categories[i].name;
		outStream << getDelimiter(i);
	}

	//account for last frame if they added entries
	unsigned int numActualFrames = frameIndex;
	if (categoryIndex == numProfileCategories)
		numActualFrames++;

	for (unsigned int frame = 0; frame < numActualFrames; frame++)
	{
		for (unsigned int cat = 0; cat < numProfileCategories; cat++)
		{
			outStream << categories[cat].samples[frame];
			outStream << getDelimiter(cat);

		}
	}
	return false;
}
void Profiler::newFrame()
{
	if (frameIndex > 0)
		assert(categoryIndex == numProfileCategories);
	frameIndex++;
	categoryIndex = 0;
}
void Profiler::addEntry(const char * categoryName, float time)
{
	assert(frameIndex < MAX_FRAME_SAMPLES);
	assert(categoryIndex < MAX_PROFILE_CATEGORIES);

	ProfileCategory& pc = categories[categoryIndex++];

	if (frameIndex == 0)
	{
		pc.name = categoryName;
		numProfileCategories++;
	}
	else
	{
		assert(pc.name == categoryName && categoryName != NULL);
		assert(categoryIndex <= numProfileCategories);
	}
	pc.samples[frameIndex] = time;
}
char Profiler::getDelimiter(unsigned int index) const
{
	return ((index + 1 < numProfileCategories) ? ',' : '\n');
}
