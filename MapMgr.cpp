#include "DxLib.h"
#include "MapMgr.h"


MapMgr::MapMgr():
	mBlockHandle(0), mNextMap(eMap::None) {
	mMap = NULL;

}

void MapMgr::initialize() {
	mBlockHandle = LoadGraph("images/block.png");
}

void MapMgr::finalize() {

}

void MapMgr::update() {

}

void MapMgr::draw() {
	//DrawGraph()
}

void MapMgr::changeMap(eMap nextMap) {
	mNextMap = nextMap;
}