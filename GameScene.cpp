#include "GameScene.h"
#include "DxLib.h"

GameScene::GameScene(ISceneChanger* changer) : BaseScene(changer), mMapMgr() {
}

//初期化
void GameScene::initialize(){
    //mBGHandle = LoadGraph();    //背景画像
    mMapMgr = new MapMgr();
}

//更新
void GameScene::update(){
    //シーン遷移
    if(CheckHitKey(KEY_INPUT_ESCAPE)!=0){ //Escキーが押されていたら
        mSceneChanger->changeScene(eScene::Menu, NULL, eStackFlag::Delete);//シーンをメニューに変更
    }
    if (FALSE) { //エンカウント判定 // TODO
        mSceneChanger->changeScene(eScene::Battle, NULL, eStackFlag::Push);//バトルシーン突入
    }

    //その他update
}

//描画
void GameScene::draw(){
    BaseScene::draw();//親クラスの描画メソッドを呼ぶ
    DrawString(0, 0,"ゲーム画面です。",GetColor(255,255,255));
    DrawString(0,20,"Escキーを押すとメニュー画面に戻ります。",GetColor(255,255,255));
}
