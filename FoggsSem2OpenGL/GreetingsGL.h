#pragma once
#include <Windows.h>
#include<gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"
#define REFRESHRATE 16
#define CUBECOUNT 200


class GreetingsGL
{
public:
	//Constructor definition
	GreetingsGL(int argc, char* argv[]);

	//THE DESTRUCTOR
	~GreetingsGL(void);

	void Display();

	void Update();
	void Keyboard(unsigned char key, int x, int y);
	/*
	void DrawPolygon();
	void DrawCube();
	void DrawCubeArray();
	void DrawIndexCube();
	void DrawCubeArrayAlt();
	void DrawIndexedCubeAlt();
	*/
private:
	float rotation;
	Camera* camera;
	Cube* cube[CUBECOUNT];
		/*
		static Vertex vertices[];
		static Color colors[];
		static Vertex indexedVertices[];
		static Color indexedColors[];
		static GLushort indices[];
		*/
		
};


