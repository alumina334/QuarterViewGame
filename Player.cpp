#include "Player.h"
#include "DxLib.h"

Player::Player(double x, double y, double z): mX(x), mY(y), mZ(z), mHandle(0){
}

void Player::initialize() {
	mHandle = LoadGraph("./images/select_block.png");
}

void Player::finalize() {
}

void Player::update() {
	if (Keyboard::keyboardGet(KEY_INPUT_W) > 0) {
		mY -= 0.2;
	}else if (Keyboard::keyboardGet(KEY_INPUT_A) > 0) {
		mX -= 0.2;
	}else if (Keyboard::keyboardGet(KEY_INPUT_S) > 0) {
		mY += 0.2;
	}else if (Keyboard::keyboardGet(KEY_INPUT_D) > 0) {
		mX += 0.2;
	}
}

void Player::draw(int x, int y) {
	DrawGraph(x - 16 , y - 32, mHandle, TRUE);
}

void Player::setXYZ(double x, double y, double z) {
	mX = x;
	mY = y;
	mZ = z;
}

void Player::getXYZ(double& x, double& y, double& z) {
	x = mX;
	y = mY;
	z = mZ;
}