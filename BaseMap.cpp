#include "BaseMap.h"
#include "DxLib.h"

BaseMap::BaseMap(IMapChanger* changer):
	mBGHandle(0) {
	mMapChanger = changer;
}

void BaseMap::finalize() {
	DeleteGraph(mBGHandle);
}

void BaseMap::draw() {
	DrawGraph(0, 0, mBGHandle, TRUE);
}