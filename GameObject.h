#pragma once

#include"Task.h"

class GameObject : public Task {
private:
	int life;
	int mX, mY, mZ;
public:
	void initialize() override;
	void finalize() override;
	void update() override;
	void draw() override;
};