#pragma once

#include "Task.h"
#include "IMapChanger.h"
#include "BaseMap.h"


class MapMgr : public Task, IMapChanger {
private:
	int mBlockHandle; 
	BaseMap* mMap; //���݃}�b�v
	eMap mNextMap; //�ړ���}�b�v
	Parameter* mParameter; // �ړ����

public:
	MapMgr();
	void initialize() override;
	void finalize() override;
	void update() override;
	void draw() override;

	void changeMap(eMap nextMap, Parameter* parameter) override;
};