#include "Clock.h"
namespace Timing 
{
	bool Clock::init()
	{
		return QueryPerformanceFrequency(&timeFrequency) && QueryPerformanceCounter(&lastFrameTimeMillisec);
	}
	bool  Clock::shutdown()
	{
		return true;
	}
	void  Clock::newFrame()
	{
		LARGE_INTEGER thisTimeMillisec;
		QueryPerformanceCounter(&thisTimeMillisec);
		LARGE_INTEGER deltaTimeMillisec;
		deltaTimeMillisec.QuadPart = thisTimeMillisec.QuadPart - lastFrameTimeMillisec.QuadPart;
		deltaTimeSeconds = ((float)deltaTimeMillisec.QuadPart) / timeFrequency.QuadPart; //converting milliseconds to float seconds
		lastFrameTimeMillisec.QuadPart = thisTimeMillisec.QuadPart; //setting last frames milliseconds elapsed to this frames milliseconds elapsed
	}
	float  Clock::deltaTime() const
	{
		return deltaTimeSeconds;
	}
}