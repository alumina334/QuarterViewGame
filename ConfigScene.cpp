#include "DxLib.h"
#include "ConfigScene.h"

ConfigScene::ConfigScene(ISceneChanger* changer): BaseScene(changer) {
}

//初期化
void ConfigScene::initialize(){
    //mBGHandle = LoadGraph();    //背景画像のロード
}

//更新
void ConfigScene::update(){
    if(CheckHitKey(KEY_INPUT_ESCAPE)!=0){ //Escキーが押されていたら
        mSceneChanger->changeScene(eScene::Title, NULL, eStackFlag::Pop);//シーンをメニューに変更
    }
}

//描画
void ConfigScene::draw(){
    BaseScene::draw();//親クラスの描画メソッドを呼ぶ
    DrawString(0, 0,"設定画面です。",GetColor(255,255,255));
    DrawString(0,20,"Escキーを押すとメニュー画面に戻ります。",GetColor(255,255,255));
}
