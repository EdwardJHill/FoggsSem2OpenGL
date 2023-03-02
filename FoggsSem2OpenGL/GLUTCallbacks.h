#pragma once
class GreetingsGL;

namespace GLUTCallbacks
{
	void Init(GreetingsGL* GL);

	void Display();

	void Timer(int preferredRefresh);
	void Keyboard(unsigned char key, int x, int y);
}