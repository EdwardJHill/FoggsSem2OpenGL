#include "GreetingsGL.h"
GreetingsGL::GreetingsGL(int argc, char* argv[])
{
	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
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
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Set the viewport to be the entire window
	glViewport(0, 0, 800, 800);
	//set the correct perspective.
	gluPerspective(45, 1, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
}

GreetingsGL::~GreetingsGL(void)
{
	//to do finish deleter
	delete camera;
}

void GreetingsGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	DrawCube();
	DrawPolygon();
	glFlush();
	glutSwapBuffers();

}
void GreetingsGL::DrawPolygon()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -20.0f);
	
	glRotatef(rotation, 1.0f, 1.0f, 0.5f);
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(-0.25, -0.5);
		glVertex2f(0.0, -0.1);
		glVertex2f(0.25, -0.5);
		glEnd();

	}

	glPopMatrix();
	glPushMatrix();
	glRotatef(rotation, 0.0f, 1.0f, -1.0f);
	glutWireIcosahedron();
	glutWireCube(0.5);
	glutWireTeapot(0.1);

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
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x,camera->center.y,camera->center.z,camera->up.x,camera->up.y,camera->up.z);
	glutPostRedisplay();
	rotation += 0.5f;
	if (rotation >= 360.0f)
		rotation = 0.0f;
}

void GreetingsGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
	{
		rotation += 1.0f;
		camera->eye.x += 0.1;
	}
	if (key == 'a')
	{
		rotation -= 2.0f;
		camera->eye.z -= 0.1;
	}
}

void GreetingsGL::DrawCube()
{
	glBegin(GL_TRIANGLES);
	// face v0-v1-v2
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	// face v2-v3-v0
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);

	// face v0-v3-v4
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	// face v4-v5-v0
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);

	// face v0-v5-v6
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	// face v6-v1-v0
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);

	// face  v1-v6-v7
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	// face v7-v2-v1
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	// face v7-v4-v3
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	// face v3-v2-v7
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);

	// face v4-v7-v6
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	// face v6-v5-v4
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);

	glEnd();
}





