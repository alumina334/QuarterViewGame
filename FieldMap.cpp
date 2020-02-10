#include "FieldMap.h"
#include "DxLib.h"


FieldMap::FieldMap(IMapChanger* changer, Parameter* parameter) :
	BaseMap(changer, parameter), mPlayer(0, 0, 0), mMapData(){
	mMapChip.resize(3);
	LoadDivGraph("images/block.png", 3, 3, 1, 32, 32, &mMapChip[0]);
}

void FieldMap::initialize() {
	mPlayer.initialize();
	mPlayer.setXYZ(mParameter->get("StartX"), mParameter->get("StartY"), mParameter->get("StartZ"));

	mMapData.resize(32);
	for (size_t i = 0; i < 32; i++) {
		mMapData[i].resize(32);
		for (size_t j = 0; j < 32; j++) {
			mMapData[i][j].resize(32);
		}
	}
	for (int y = 0; y < 32; y++) {
		for (int x = 0; x < 32; x++) {
			mMapData[0][y][x] = 0;
		}
	}
}

void FieldMap::finalize() {
}

void FieldMap::update() {
	if (Keyboard::keyboardGet(KEY_INPUT_BACK) == 1) {
		mMapChanger->changeMap(eMap::FieldMap, NULL);
	}
	mPlayer.update();
}

void FieldMap::draw() {
	DrawGraph(100, 100, mMapChip[1], TRUE);

	for (int y = 0; y < 32; y++) {
		for (int x = 0; x < 32; x++) {
			double px, py, pz;
			mPlayer.getXYZ(px, py, pz);
			DrawGraph(400 + 16 * (x - px - y + py - 1), 300 + 8 * (x - px + y - py - 2), mMapChip[mMapData[0][y][x]], TRUE);
		}
	}

	mPlayer.draw(400, 300);
}