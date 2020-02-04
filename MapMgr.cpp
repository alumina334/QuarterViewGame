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
	もしnextMapが設定されていた場合
		mMap.finalize();
		mMap =new FieldMap(this, nextMap ,parameter); FieldMap側でマップチップ、敵情報など読み込み
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