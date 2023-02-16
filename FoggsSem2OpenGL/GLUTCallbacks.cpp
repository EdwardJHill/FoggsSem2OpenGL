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
}