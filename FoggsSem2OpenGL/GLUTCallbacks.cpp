#include "GLUTCallbacks.h"
#include "GreetingsGL.h"

namespace GLUTCallbacks
{
	namespace
	{
		GreetingsGL* greetingsGL = nullptr;
	}
	void Init(GreetingsGL* gl)
	{
		greetingsGL = gl;
	}
	void Display()
	{
		if (greetingsGL != nullptr)
		{
			greetingsGL->Display();
		}
	}
	void Timer(int preferredRefresh)
	{
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		greetingsGL->Update();
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
		glutTimerFunc(preferredRefresh - updateTime, GLUTCallbacks::Timer, preferredRefresh);
	}

	void Keyboard(unsigned char key, int x, int y)
	{
		greetingsGL->Keyboard(key, x, y);
	}

}