#include "DxLib.h"
#include "MapMgr.h"


MapMgr::MapMgr():
	mBlockHandle(0), mNextMap(eMap::None){
	mParameter = new Parameter();
	mParameter->set("StartX", 0);
	mParameter->set("StartY", 0);
	mParameter->set("StartZ", 0);
	mMapStack.push(std::make_shared<FieldMap>(this, mParameter));
}

void MapMgr::initialize() {
	mMapStack.top()->initialize();
	// mBlockHandle = LoadGraph("images/block.png");
}

void MapMgr::finalize() {

}

void MapMgr::update() {
	if (mNextMap != eMap::None) {  // 次のマップが設定されていたら
		mMapStack.top()->finalize();  // 終了処理してから
		switch (mNextMap) {              // 分岐
		case eMap::FieldMap:
			mMapStack.pop();
			mParameter->set("StartX", 0);
			mParameter->set("StartY", 0);
			mParameter->set("StartZ", 0);
			mMapStack.push(std::make_shared<FieldMap>(this, mParameter));
			break;
		case eMap::BattleMap:
			//mMapStack.push(std::make_shared<BattleMap>(this));
			break;
		default:
			break;
		}
		mMapStack.top()->initialize();
	}
	mMapStack.top()->update();
}

void MapMgr::draw() {
	mMapStack.top()->draw();
}

void MapMgr::changeMap(eMap nextMap, Parameter* parameter) {
	mNextMap = nextMap;
}