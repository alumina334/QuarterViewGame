#include "DxLib.h"
#include "MapMgr.h"


MapMgr::MapMgr():
	mBlockHandle(0), mNextMap(eMap::None), mParameter(NULL){
	mMap = NULL;

}

void MapMgr::initialize() {
	// mBlockHandle = LoadGraph("images/block.png");
}

void MapMgr::finalize() {

}

void MapMgr::update() {
	/*
	����nextMap���ݒ肳��Ă����ꍇ
		mMap.finalize();
		mMap =new FieldMap(this, nextMap ,parameter); FieldMap���Ń}�b�v�`�b�v�A�G���ȂǓǂݍ���
		mMap.initialize();
	mMap.update()
	*/
}

void MapMgr::draw() {
	//mMap.draw()
}

void MapMgr::changeMap(eMap nextMap, Parameter* parameter) {
	mNextMap = nextMap;
}