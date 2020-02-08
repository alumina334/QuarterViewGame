#include "TitleScene.h"
#include "Keyboard.h"
#include "DxLib.h"

eTitle TitleScene::mNowSelect;

TitleScene::TitleScene(ISceneChanger* changer) : BaseScene(changer) {
}


void TitleScene::initialize(){
    mNowSelect = eTitle::Game;
    //mBGHandle = LoadGraph("images/Scene_Menu.png");    //�w�i�摜�̃��[�h
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
        case eTitle::Edit:
            mSceneChanger->changeScene(eScene::Edit, NULL, eStackFlag::Push);
            break;
        }
    }
}


void TitleScene::draw(){
    BaseScene::draw();//�e�N���X�̕`�惁�\�b�h���Ă�
    DrawString(0, 0,"���j���[��ʂł��B",GetColor(255,255,255));
    DrawString(20,20,"�Q�[�����",GetColor(255,255,255));
    DrawString(20,40,"�ݒ���",GetColor(255,255,255));
    DrawString(20, 60, "�G�f�B�b�g���", GetColor(255, 255, 255));
    int y = 20;
    switch (mNowSelect)
    {
    case eTitle::Game:
        y = 20;
        break;
    case eTitle::Config:
        y = 40;
        break;
    case eTitle::Edit:
        y = 60;
        break;
    }
    DrawString(0, y, "��", GetColor(255, 255, 255));
}
