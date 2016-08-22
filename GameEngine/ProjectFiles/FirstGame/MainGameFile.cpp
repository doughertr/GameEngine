#include <QtWidgets\qapplication.h>
#include <QtWidgets\qwidget.h>
#include "MyOpenGlWindow.h"

#include <Windows.h>
#include <QtCore\qdebug.h>

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);
	MyOpenGlWindow GlWindow;
	if (!GlWindow.init())
		return -1;
	GlWindow.show();

	int errorCode = application.exec();
	if (!GlWindow.shutdown())
		errorCode |= 1;
	return errorCode;
}