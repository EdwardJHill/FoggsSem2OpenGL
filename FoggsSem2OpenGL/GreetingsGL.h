#pragma once
#include <Windows.h>
#include<gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#define REFRESHRATE 16
class GreetingsGL
{
	public:
	//Constructor definition
	GreetingsGL(int argc, char* argv[]);

	//THE DESTRUCTOR
	~GreetingsGL(void);

	void Display();
	void DrawPolygon();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	private:
		float rotation;
};


