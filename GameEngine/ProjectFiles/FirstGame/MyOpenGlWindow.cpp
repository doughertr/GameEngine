#include <gl\glew.h>
#include "MyOpenGlWindow.h"
#include <cassert>
#include <QtGui\QKeyEvent>
#include <Math\Vector3.h>
#include <Math\Matrix3.h>
#include <Timing\Clock.h>
using Math::Vector3;
using Math::Matrix3;

using Timing::Clock;

namespace {
	static Vector3 verticies[] =
	{
		Vector3(+0.0f ,  sqrt(0.02f), 1.0f),
		Vector3(-0.1f ,  -0.1f,       1.0f),
		Vector3(+0.1f ,  -0.1f,       1.0f),
	};
	const unsigned int NUM_VERTS = sizeof(verticies) / sizeof(*verticies);
	Vector3 shipPosition(0.0f, 0.0f, 1.0f);
	Vector3 shipVelocity;
	Vector3 shipAcceleration;
	Matrix3 shipMatrix;
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
	Vector3 viewportLocation;
	viewportLocation.x = width() / 2 - minSize / 2;
	viewportLocation.y = height() / 2 - minSize / 2;
	glViewport(viewportLocation.x, viewportLocation.y, minSize, minSize);

	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	Vector3 transformedVerts[NUM_VERTS];
	Matrix3 translator = Matrix3::translate(shipPosition);
	Matrix3 rotator = Matrix3::rotateZ(shipOrientation);
	
	shipMatrix = translator * rotator;


	for (unsigned int i = 0; i < NUM_VERTS; i++)
	{
		transformedVerts[i] = shipMatrix * verticies[i];
	}
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(transformedVerts), transformedVerts);

	
	glDrawArrays(GL_TRIANGLES, 0, 3);

	//text rendering not working
	renderText(10, 10, 0, QString("Hello"), QFont("Arial", 12, QFont::Bold, false));


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
	const float ACCELERATION_MAGNETUDE = 0.5f * frameClock.deltaTime();
	//if(GetAsyncKeyState(0x57)) //W key
	//	shipVelocity += ACCELERATION_MAGNETUDE * shipMatrix[];
	//if (GetAsyncKeyState(0x41)) //A key
	//	shipVelocity -= ACCELERATION_MAGNETUDE;
	//if (GetAsyncKeyState(0x53)) //S key
	//	shipVelocity -= ACCELERATION_MAGNETUDE;
	//if (GetAsyncKeyState(0x44)) //D key
	//	shipVelocity += ACCELERATION_M AGNETUDE;

	Vector3 direction(shipMatrix[1]);

	if (GetAsyncKeyState(VK_SPACE))
		shipVelocity += direction * ACCELERATION_MAGNETUDE;
}
