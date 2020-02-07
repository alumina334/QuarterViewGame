#pragma once

#include "IMapChanger.h"
#include "FieldMap.h"
#include <stack>
#include <memory>


class MapMgr : public IMapChanger, Task {
private:
	std::stack<std::shared_ptr<BaseMap>> mMapStack; //���݃}�b�v
	int mBlockHandle; 
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