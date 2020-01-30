#pragma once

#include "Task.h"
#include "IMapChanger.h"
#include "BaseMap.h"


class MapMgr : public Task, IMapChanger {
private:
	int mBlockHandle; 
	BaseMap* mMap; //現在マップ
	eMap mNextMap; //移動先マップ

public:
	MapMgr();
	void initialize() override;
	void finalize() override;
	void update() override;
	void draw() override;

	void changeMap(eMap nextMap) override;
};