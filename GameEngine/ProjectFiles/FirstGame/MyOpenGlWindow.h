#ifndef GAME_MY_GL_WINDOW
#define GAME_MY_GL_WINDOW
#include <QtOpenGL\qgl.h>
#include <QtCore\qtimer.h>

class MyOpenGlWindow : public QGLWidget
{
	Q_OBJECT; //preprocessor macro

	GLuint vertexBufferID;
	QTimer gameLoop;
protected:
	void initializeGL();
	void paintGL();
private slots:
	void updateGame();
	void updateVelocity();
	void updatePosition();
	void updateRotation();
public:
	bool init();
	bool shutdown();
};

#endif