#ifndef ENGINE_WINDOW
#define ENGINE_WINDOW

#include <string>

class GLFWwindow;

namespace UI
{
class Window
{
public:
	Window(std::string windowTitle);
	~Window();

	void Init();
	void Render();

private:
	GLFWwindow *m_glWindow;
};
}

#endif // !ENGINE_WINDOW
