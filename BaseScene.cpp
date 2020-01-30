#include "BaseScene.h"
#include "DxLib.h"

BaseScene::BaseScene(ISceneChanger* changer) : 
    mBGHandle(0) {
    mSceneChanger = changer;
}

void BaseScene::finalize(){
    DeleteGraph(mBGHandle);
}

void BaseScene::draw(){
    DrawGraph(0, 0, mBGHandle, TRUE);
}
