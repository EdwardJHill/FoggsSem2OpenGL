#pragma once
#include <Windows.h>
#include<gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#define REFRESHRATE 16
struct Vector3 {
	float x;
	float y;
	float z;
};
struct Camera{
	Vector3 eye;
	Vector3 center;
	Vector3 up;
};
struct Color {
	GLfloat r, g, b;
};
struct Vertex {
	GLfloat x, y, z;
};

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
	private:
		float rotation;
		Camera* camera;
		static Vertex vertices[];
		static Color colors[];
		static Vertex indexedVertices[];
		static Color indexedColors[];
		static GLushort indices[];
		
};


