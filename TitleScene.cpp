#include "TitleScene.h"
#include "Keyboard.h"
#include "DxLib.h"

eMenu TitleScene::mNowSelect;

TitleScene::TitleScene(ISceneChanger* changer) : BaseScene(changer) {
}


void TitleScene::initialize(){
    mNowSelect = eMenu::Game;
    //mBGHandle = LoadGraph("images/Scene_Menu.png");    //背景画像のロード
}


void TitleScene::update(){
    if (Keyboard::keyboardGet(KEY_INPUT_S) == 1) {
        mNowSelect = (eMenu)(((int)mNowSelect + 1) % (int)eMenu::Num);
    }
    if (Keyboard::keyboardGet(KEY_INPUT_W) == 1) {
        mNowSelect = (eMenu)(((int)mNowSelect + ((int)eMenu::Num - 1)) % (int)eMenu::Num);
    }
    if (Keyboard::keyboardGet(KEY_INPUT_RETURN) == 1) {
        switch (mNowSelect) {
        case eMenu::Game:
            mSceneChanger->changeScene(eScene::Game, NULL, eStackFlag::Delete);
            break;
        case eMenu::Config:
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
    case eMenu::Game:
        y = 20;
        break;
    case eMenu::Config:
        y = 40;
        break;
    }
    DrawString(0, y, "→", GetColor(255, 255, 255));
}
