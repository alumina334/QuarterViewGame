#include "FieldMap.h"
#include "DxLib.h"

FieldMap::FieldMap(IMapChanger* changer) :
	BaseMap(changer) {
	LoadDivGraph("images/block.png", 2, 2, 1, 32, 32, mMapChip);
}

void FieldMap::initialize() {

}

void FieldMap::finalize() {
}

void FieldMap::update() {
}

void FieldMap::draw() {
	DrawGraph(100, 100, mMapChip[1], TRUE);
}