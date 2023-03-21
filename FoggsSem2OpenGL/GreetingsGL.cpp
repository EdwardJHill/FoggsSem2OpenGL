#include "GreetingsGL.h"

GreetingsGL::GreetingsGL(int argc, char* argv[])
{
	camera = new Camera();
	
	for (int i = 0; i < CUBECOUNT; i++)
	{
		cube[i] = new Cube(((rand() % 200) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
	

	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 2.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	rotation = 0.0f;
	
	glutInit(&argc, argv);
	//window shit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
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
	gluPerspective(45, 1, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glCullFace(GL_BACK);
	glutMainLoop();
}
GreetingsGL::~GreetingsGL(void)
{
	//to do finish deleter
	delete camera;
	delete cube;
}
void GreetingsGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	for (int i = 0; i < CUBECOUNT; i++)
	{
		cube[i]->Draw();
	}
	glPopMatrix();
	glFlush();
	glutSwapBuffers();

}

void GreetingsGL::Update()
{
	for (int i = 0; i < CUBECOUNT; i++)
	{
		cube[i]->Update();
	}
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
		camera->eye.x += 0.1;
	}
	if (key == 'a')
	{
		camera->eye.x -= 0.1;
	}
	if (key == 'w')
	{
		camera->eye.y += 0.1;
	}
	if (key == 's')
	{
		camera->eye.y -= 0.1;
	}
	if (key == 'z')
	{
		camera->eye.z += 0.1;
	}
	if (key == 'x')
	{
		camera->eye.z -= 0.1;
	}
}











