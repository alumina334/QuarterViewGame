#pragma once

#include "IMapChanger.h"
#include "FieldMap.h"
#include <stack>
#include <memory>


class MapMgr : public IMapChanger, Task {
private:
	std::stack<std::shared_ptr<BaseMap>> mMapStack; //現在マップ
	int mBlockHandle; 
	eMap mNextMap; //移動先マップ
	Parameter* mParameter; // 移動情報

public:
	MapMgr();
	void initialize() override;
	void finalize() override;
	void update() override;
	void draw() override;

	void changeMap(eMap nextMap, Parameter* parameter) override;
};