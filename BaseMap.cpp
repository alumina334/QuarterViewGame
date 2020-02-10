#include "BaseMap.h"
#include "DxLib.h"

BaseMap::BaseMap(IMapChanger* changer, Parameter* parameter):
	mBGHandle(0) {
	mMapChanger = changer;
	mParameter = parameter;
}

void BaseMap::finalize() {
	DeleteGraph(mBGHandle);
}

void BaseMap::draw() {
	DrawGraph(0, 0, mBGHandle, TRUE);
}