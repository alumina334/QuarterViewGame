#include "FieldMap.h"
#include "DxLib.h"

FieldMap::FieldMap(IMapChanger* changer, Parameter* parameter) :
	BaseMap(changer) {
	mMapChip = LoadGraph("images/block.png");
}

void FieldMap::initialize() {

}

void FieldMap::finalize() {
}

void FieldMap::update() {
}

void FieldMap::draw() {
	DrawGraph(0,0,mMapChip, TRUE);
}