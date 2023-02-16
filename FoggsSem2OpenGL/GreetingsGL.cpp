#include "GreetingsGL.h"
GreetingsGL::GreetingsGL(int argc, char* argv[])
{
	glutInit(&argc, argv);
	GLUTCallbacks::Init(this);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("Simple OpenGl Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutMainLoop();
}

void GreetingsGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	DrawPolygon();
	glFlush();

}
void GreetingsGL::DrawPolygon()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
		glVertex2f(-0.25, -0.5);
		glVertex2f(0.0, -0.1);
		glVertex2f(0.25, -0.5);
		glEnd();
	}
	glBegin(GL_POLYGON);
	{
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		glVertex2f(-0.25, 0.8);
		glVertex2f(0.35, 0.5);
		glVertex2f(0.55, 0.2);
		glEnd();
	}
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
		glVertex2f(-0.15, -0.0);
		glVertex2f(0.0, 0.5);
		glVertex2f(0.15, -0.0);
		glEnd();
	}
	glBegin(GL_POLYGON);
	{
		glColor4f(0.0f, 0.0f, 7.0f, 0.0f);
		glVertex2f(-0.8, 0.4);
		glVertex2f(-0.8, 0.2);
		glVertex2f(-0.4, 0.2);
		glEnd();
	}
}
/*
scalene and obtuse(fatass)	
	glVertex2f(-0.55, 0.5);
	glVertex2f(0.35, 0.3);
	glVertex2f(0.75, -0.5);

Isoceles
	glVertex2f(-0.25, -0.5);
	glVertex2f(0.0, 0.7);
	glVertex2f(0.25, -0.5);

close enough to an equilateral and acute
	glVertex2f(-0.25, -0.5);
	glVertex2f(0.0, -0.1);
	glVertex2f(0.25, -0.5);

right angle
	glVertex2f(-0.8, 0.4);
	glVertex2f(-0.8, 0.2);
	glVertex2f(-0.4, 0.2);
*/
