#ifndef ENGINE_CLOCK
#define ENGINE_CLOCK
#include <Windows.h>
namespace Timing
{
	class __declspec(dllexport) Clock
	{
		LARGE_INTEGER timeFrequency;
		LARGE_INTEGER timeLastFrame;
		LARGE_INTEGER deltaLastFrame;
		float deltaTime;
	public:
		bool init();
		bool shutdown();
		void newFrame();
		float timeElapsedLastFrame() const;
	};
}
#endif 
