#include "GreetingsGL.h"
GreetingsGL::GreetingsGL(int argc, char* argv[])
{
	rotation = 0.0f;
	glutInit(&argc, argv);
	//window shit
	glutInitDisplayMode(GLUT_DOUBLE);
	GLUTCallbacks::Init(this);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Simple OpenGl Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	//keybaord
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutMainLoop();
}

void GreetingsGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	
	DrawPolygon();
	glFlush();
	glutSwapBuffers();

}
void GreetingsGL::DrawPolygon()
{
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
		glVertex2f(-0.25, -0.5);
		glVertex2f(0.0, -0.1);
		glVertex2f(0.25, -0.5);
		glEnd();

	}

	glPopMatrix();
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
void GreetingsGL::Update()
{
	glutPostRedisplay();
	rotation += 0.5f;
	if (rotation >= 360.0f)
		rotation = 0.0f;
}

void GreetingsGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
		rotation += 1.0f;
	if (key == 'a')
		rotation -= 2.0f;
}
