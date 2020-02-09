#pragma once

#include "Task.h"

class Keyboard{
private:
	Keyboard();
	static int mKey[256];
public:
	static void update(); 
	static void setNum(int keyCode, int num);
	static int keyboardGet(int keyCode);
};