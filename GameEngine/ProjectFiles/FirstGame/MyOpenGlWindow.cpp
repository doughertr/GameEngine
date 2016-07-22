#include <gl\glew.h>
#include "MyOpenGlWindow.h"
#include <cassert>
#include <Math\vector2.h>
#include <Timing\Clock.h>
using Math::Vector2;
using Timing::Clock;
namespace {
	static Vector2 verticies[] =
	{
		Vector2(+0.0f ,  +0.1f),
		Vector2(-0.1f ,  -0.1f),
		Vector2(+0.1f ,  -0.1f),
	};
	const unsigned int NUM_VERTS = sizeof(verticies) / sizeof(*verticies);
	Vector2 shipPosition(0.0f, 0.0f);
	Clock frameClock;
}

bool MyOpenGlWindow::init() 
{
	assert(frameClock.init());

}
void MyOpenGlWindow::initializeGL()
{
	GLenum errorCode = glewInit();
	assert(errorCode == 0);

	
	glGenBuffers(1, &vertexBufferID); //make room on GPU for verts
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID); //bind buffer
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), NULL, GL_DYNAMIC_DRAW); // send verts to the GPU!
	connect(&gameLoop, SIGNAL(timeout()), this, SLOT(updateGame()));
	gameLoop.start(0);
}
void MyOpenGlWindow::paintGL() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	Vector2 translatedVerts[NUM_VERTS];
	for (unsigned int i = 0; i < NUM_VERTS; i++)
	{
		translatedVerts[i] = verticies[i] + shipPosition;
	}
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(translatedVerts), translatedVerts);

	glDrawArrays(GL_TRIANGLES, 0, 3);
	
}

void MyOpenGlWindow::updateGame()
{
	Vector2 velocity(0.001f, 0.001f);
	shipPosition = shipPosition + velocity;
	repaint();
}

bool MyOpenGlWindow::shutdown()
{
	return frameClock.shutdown();
}