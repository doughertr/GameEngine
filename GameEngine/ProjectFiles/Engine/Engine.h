#ifndef ENGINE_ENGINE_CORE
#define ENGINE_ENGINE_CORE

#define WINDOW_WIDTH  600
#define WINDOW_HEIGHT 480

#include <vector>
#include <unordered_map>

// ==============================
// Forward Declarations
// ==============================
class GLFWwindow;

namespace Timing {
	class Clock;
}
namespace Objects {
	class GameObject;
}
// ==============================

class Engine
{
public:
	Engine();
	~Engine();

	void Init();
	void AddToGame(Objects::GameObject obj);

	static void errorCallback(int error, const char *description);
	static void keyPressCallback(GLFWwindow *window, int key, int seconds, int action, int mods);
private:
	void tick();

	void clear();
	void updateGameObjects();
	void render();

	void initGameClock();
	void initGameWindow();
	void initGL();

private:
	GLFWwindow *m_gameWindow;

	Timing::Clock *m_gameClock;

	std::unordered_map<unsigned int, Objects::GameObject> m_gameObjects;

};
#endif 