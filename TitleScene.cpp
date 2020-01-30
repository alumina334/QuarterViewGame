#include "TitleScene.h"
#include "Keyboard.h"
#include "DxLib.h"

eMenu TitleScene::mNowSelect;

TitleScene::TitleScene(ISceneChanger* changer) : BaseScene(changer) {
}


void TitleScene::initialize(){
    mNowSelect = eMenu::Game;
    //mBGHandle = LoadGraph("images/Scene_Menu.png");    //�w�i�摜�̃��[�h
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
    BaseScene::draw();//�e�N���X�̕`�惁�\�b�h���Ă�
    DrawString(0, 0,"���j���[��ʂł��B",GetColor(255,255,255));
    DrawString(20,20,"�Q�[�����",GetColor(255,255,255));
    DrawString(20,40,"�ݒ���",GetColor(255,255,255));
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
    DrawString(0, y, "��", GetColor(255, 255, 255));
}
