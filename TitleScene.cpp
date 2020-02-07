#include "TitleScene.h"
#include "Keyboard.h"
#include "DxLib.h"

eTitle TitleScene::mNowSelect;

TitleScene::TitleScene(ISceneChanger* changer) : BaseScene(changer) {
}


void TitleScene::initialize(){
    mNowSelect = eTitle::Game;
    //mBGHandle = LoadGraph("images/Scene_Menu.png");    //背景画像のロード
}


void TitleScene::update(){
    if (Keyboard::keyboardGet(KEY_INPUT_S) == 1) {
        mNowSelect = (eTitle)(((int)mNowSelect + 1) % (int)eTitle::Num);
    }
    if (Keyboard::keyboardGet(KEY_INPUT_W) == 1) {
        mNowSelect = (eTitle)(((int)mNowSelect + ((int)eTitle::Num - 1)) % (int)eTitle::Num);
    }
    if (Keyboard::keyboardGet(KEY_INPUT_RETURN) == 1) {
        switch (mNowSelect) {
        case eTitle::Game:
            mSceneChanger->changeScene(eScene::Game, NULL, eStackFlag::Delete);
            break;
        case eTitle::Config:
            mSceneChanger->changeScene(eScene::Config, NULL, eStackFlag::Push);
            break;
        }
    }
}


void TitleScene::draw(){
    BaseScene::draw();//親クラスの描画メソッドを呼ぶ
    DrawString(0, 0,"メニュー画面です。",GetColor(255,255,255));
    DrawString(20,20,"ゲーム画面",GetColor(255,255,255));
    DrawString(20,40,"設定画面",GetColor(255,255,255));
    int y = 20;
    switch (mNowSelect)
    {
    case eTitle::Game:
        y = 20;
        break;
    case eTitle::Config:
        y = 40;
        break;
    }
    DrawString(0, y, "→", GetColor(255, 255, 255));
}
