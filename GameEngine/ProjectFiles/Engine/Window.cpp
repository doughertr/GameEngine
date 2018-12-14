#include "Window.h"

#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <string>

#define WINDOW_WIDTH  600
#define WINDOW_HEIGHT 480

namespace UI
{
	Window::Window(std::string windowTitle)
	{
		m_glWindow = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, windowTitle.c_str(), NULL, NULL);
	}

	Window::~Window()
	{
	}

	void Window::Init()
	{
	}

	void Window::Render()
	{
	}

}
