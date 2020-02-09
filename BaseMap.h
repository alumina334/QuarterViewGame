#pragma once

#include "Task.h"
#include "IMapChanger.h"
#include "Keyboard.h"

enum class eChipSet {
	Default,

	Num,
};

class BaseMap : public Task {
protected:
	IMapChanger* mMapChanger;
	int mBGHandle;
public:
	BaseMap(IMapChanger* changer);
	virtual void initialize() override {}
	virtual void finalize() override;
	virtual void update() override {}
	virtual void draw() override;
};