#include <QtWidgets\qapplication.h>
#include <QtWidgets\qwidget.h>
#include "MyOpenGlWindow.h"
#include <Windows.h>
#include <QtCore\qdebug.h>

int main(int argc, char* argv[])
{
	//LARGE_INTEGER clockFrequency;
	//QueryPerformanceFrequency(&clockFrequency);

	//LARGE_INTEGER startTime;
	//LARGE_INTEGER endTime;
	//QueryPerformanceCounter(&startTime);
	//qDebug() << "Hello";
	//QueryPerformanceCounter(&endTime);

	//LARGE_INTEGER deltaTime;
	//deltaTime.QuadPart = endTime.QuadPart - startTime.QuadPart;

	//float secondsElapsed = ((float)deltaTime.QuadPart) / clockFrequency.QuadPart;

	QApplication application(argc, argv);
	MyOpenGlWindow GlWindow;
	GlWindow.init();
	GlWindow.show();
	int errorCode = application.exec();
	if (!GlWindow.shutdown())
		errorCode |= 1;
	return errorCode;
}