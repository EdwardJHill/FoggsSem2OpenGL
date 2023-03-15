#pragma once
#include <Windows.h>
#include<gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
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
	void DrawCube();
	void DrawCubeArray();
	void DrawIndexCube();
	void DrawCubeArrayAlt();
	void DrawIndexedCubeAlt();
	private:
		float rotation;
		Camera* camera;
		static Vertex vertices[];
		static Color colors[];
		static Vertex indexedVertices[];
		static Color indexedColors[];
		static GLushort indices[];
		
};


