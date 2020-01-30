#include "DxLib.h"
#include "Keyboard.h"

int Keyboard::mKey[256];

void Keyboard::update() {
	char tmpKey[256];
	GetHitKeyStateAll( tmpKey );
	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) {
			mKey[i] ++;
		}
		else {
			mKey[i] = 0;
		}
	}
}

int Keyboard::keyboardGet(int keyCode) {
	return mKey[ keyCode ];
}