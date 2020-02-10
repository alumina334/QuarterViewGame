#pragma once

#include "Task.h"
#include "IMapChanger.h"
#include "Keyboard.h"
#include "Parameter.h"


class BaseMap : public Task {
protected:
	IMapChanger* mMapChanger;
	Parameter* mParameter;
	int mBGHandle;
public:
	BaseMap(IMapChanger* changer, Parameter* parameter);
	virtual void initialize() override {}
	virtual void finalize() override;
	virtual void update() override {}
	virtual void draw() override;
};