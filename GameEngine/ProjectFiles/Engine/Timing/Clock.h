#ifndef ENGINE_CLOCK
#define ENGINE_CLOCK
#include <Windows.h>
namespace Timing
{
	class __declspec(dllexport) Clock
	{
		LARGE_INTEGER timeFrequency;
		LARGE_INTEGER lastFrameTimeMillisec;
		LARGE_INTEGER deltaLastFrame;
		float deltaTimeSeconds;
	public:
		bool init();
		bool shutdown();
		void newFrame();
		float deltaTime() const;
	};
}
#endif 
