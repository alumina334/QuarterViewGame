#pragma once

#include "Task.h"
#include "IMapChanger.h"

class BaseMap : public Task {
private:
	IMapChanger* mMapChanger;
	int mBGHandle;
public:
	BaseMap(IMapChanger* changer);
	void initialize() override {}
	void finalize() override;
	void update() override {}
	void draw() override;
};