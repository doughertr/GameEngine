#include <gl\glew.h>
#include "MyOpenGlWindow.h"
#include <cassert>
#include <QtGui\QKeyEvent>
#include <Math\Vector2.h>
#include <Math\Matrix2.h>
#include <Timing\Clock.h>
using Math::Vector2;
using Math::Matrix2;
using Timing::Clock;

namespace {
	static Vector2 verticies[] =
	{
		Vector2(+0.0f ,  +0.1f),
		Vector2(-0.1f ,  -0.1f),
		Vector2(+0.1f ,  -0.1f),
	};
	const unsigned int NUM_VERTS = sizeof(verticies) / sizeof(*verticies);
	Vector2 shipPosition;
	Vector2 shipVelocity;
	float shipOrientation = 0.0f;
	Clock frameClock;
}

bool MyOpenGlWindow::init() 
{
	return frameClock.init();

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
	int minSize = std::min(width(), height());
	Vector2 viewportLocation;
	viewportLocation.x = width() / 2 - minSize / 2;
	viewportLocation.y = height() / 2 - minSize / 2;
	glViewport(viewportLocation.x, viewportLocation.y, minSize, minSize);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	Matrix2 op = Matrix2::rotate(shipOrientation);
	Vector2 transformedVerts[NUM_VERTS];
	for (unsigned int i = 0; i < NUM_VERTS; i++)
	{
		transformedVerts[i] = op * verticies[i];
		transformedVerts[i] += shipPosition;
	}
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(transformedVerts), transformedVerts);

	glDrawArrays(GL_TRIANGLES, 0, 3);
	
}

void MyOpenGlWindow::updateGame()
{
	frameClock.newFrame();
	updateRotation();
	updateVelocity();
	updatePosition();
	repaint();
}

bool MyOpenGlWindow::shutdown()
{
	return frameClock.shutdown();
}
void MyOpenGlWindow::updatePosition()
{
	shipPosition += shipVelocity * frameClock.deltaTime();
}
void MyOpenGlWindow::updateRotation()
{
	const float ANGULAR_MOVEMENT = 0.1f;
	
	if (GetAsyncKeyState(VK_RIGHT)) 
		shipOrientation -= ANGULAR_MOVEMENT;
	if (GetAsyncKeyState(VK_LEFT))
		shipOrientation += ANGULAR_MOVEMENT;
}
void MyOpenGlWindow::updateVelocity()
{
	const float ACCELERATION = 0.5f * frameClock.deltaTime();
	if(GetAsyncKeyState(0x57)) //W key
		shipVelocity.y += ACCELERATION;
	if (GetAsyncKeyState(0x41)) //A key
		shipVelocity.x -= ACCELERATION;
	if (GetAsyncKeyState(0x53)) //S key
		shipVelocity.y -= ACCELERATION;
	if (GetAsyncKeyState(0x44)) //D key
		shipVelocity.x += ACCELERATION;
}
