#pragma once

#include "Task.h"
#include "Keyboard.h"

class Player: public Task {
private:
	int mHandle;
	double mX;
	double mY;
	double mZ;
public:
	Player(double x, double y, double z);
	void initialize() override;
	void finalize() override;
	void update() override;
	void draw() override {}

	void draw(int x, int y);
	void setXYZ(double x, double y, double z);
	void getXYZ(double& x, double& y, double& z);
};