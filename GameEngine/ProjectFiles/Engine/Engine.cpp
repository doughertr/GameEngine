#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

#include "Engine.h"
#include "Math\Vector3.h"
#include "Math\Matrix3.h"
#include "Timing\Clock.h"
#include "Visuals\Mesh.h"
#include "Objects\GameObject.h"

using namespace std;
using namespace Timing;
using namespace Math;
using namespace Visuals;
using namespace Objects;


Engine::Engine() : m_gameObjects()
{
	m_gameClock = new Clock();
}

Engine::~Engine()
{
	delete m_gameClock;
}

void Engine::Init()
{
	initGL();

	initGameClock();
	initGameWindow();

	// Start game loop
	tick();
}

void Engine::tick()
{
	while (!glfwWindowShouldClose(m_gameWindow))
	{
		// Increment game clock
		m_gameClock->newFrame();

		float ratio;
		int width, height;

		glfwGetFramebufferSize(m_gameWindow, &width, &height);
		ratio = width / height;

		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(m_gameWindow);
		glfwPollEvents();
	}
}

void Engine::AddToGame(GameObject obj)
{
	Mesh objMesh = obj.GetMesh();

	unsigned int bufferID;
	glGenBuffers(1, &bufferID); // Create buffer ID

	m_gameObjects.insert({ bufferID, obj }); // Add buffer to list of active buffers

	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, objMesh.GetNumVerts(), objMesh.GetVerts(), GL_DYNAMIC_DRAW); // Assign data to given buffer
}

void Engine::clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Engine::updateGameObjects()
{
	for (auto& obj : m_gameObjects)
	{
		// Update object
		obj.second.Update();

		// Update object position relative to velocity
		obj.second.position += obj.second.velocity * m_gameClock->deltaTime();
	}
}

void Engine::render()
{
	for (auto& obj : m_gameObjects)
	{
		Vector3 objPos = obj.second.position;

		Vector3 *verts = obj.second.GetMesh().GetVerts();
		int numVerts = obj.second.GetMesh().GetNumVerts();

		// Get transformation data
		Matrix3 translator = Matrix3::translate(objPos);
		Matrix3 rotator = Matrix3::rotateZ(30);

		Matrix3 transformMatrix = translator * rotator;

		// Apply transformation to all verticies
		for (int i = 0; i < numVerts; i++)
		{
			verts[i] = translator * verts[i];
		}
		obj.second.GetMesh().SetVerts(verts, numVerts);
	}
}

void Engine::initGameClock()
{
	if (!m_gameClock->init())
	{
		cout << "Error: Could not initialize game clock" << endl;

		exit(1);
	}
}

void Engine::initGameWindow()
{

	// Create and initialize game window
	m_gameWindow = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Ryan's Engine", NULL, NULL);
	if (!m_gameWindow)
	{
		glfwTerminate();
		std::cerr << "Error: Could not initialize game window" << std::endl;
		exit(1);
	}

	// Set key press callback for this window
	glfwSetKeyCallback(m_gameWindow, keyPressCallback);

	// Make window current for calling thread
	glfwMakeContextCurrent(m_gameWindow);

	// Enable VSYNC
	glfwSwapInterval(1);
}

void Engine::initGL()
{
	if (glewInit())
	{
		std::cerr << "Error: Could not initialize GLEW" << std::endl;
	}
	glfwSetErrorCallback(errorCallback);
	if (!glfwInit())
	{
		std::cerr << "Error: Could not initialize GLFW library" << std::endl;
		exit(1);
	}
}

void Engine::errorCallback(int error, const char * description)
{
	std::cerr << "Error: " << error << ": " << description << std::endl;
	exit(1);
}

void Engine::keyPressCallback(GLFWwindow * window, int key, int seconds, int action, int mods)
{
	// Close if escape is pressed
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}
