#pragma once
#include <Windows.h>
#include<gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
class GreetingsGL
{
	public:
	//Constructor definition
	GreetingsGL(int argc, char* argv[]);

	//THE DESTRUCTOR
	~GreetingsGL(void);
	void Display();
	void DrawPolygon();

};


