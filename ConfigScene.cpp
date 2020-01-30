#include "DxLib.h"
#include "ConfigScene.h"

ConfigScene::ConfigScene(ISceneChanger* changer): BaseScene(changer) {
}

//������
void ConfigScene::initialize(){
    //mBGHandle = LoadGraph();    //�w�i�摜�̃��[�h
}

//�X�V
void ConfigScene::update(){
    if(CheckHitKey(KEY_INPUT_ESCAPE)!=0){ //Esc�L�[��������Ă�����
        mSceneChanger->changeScene(eScene::Title, NULL, eStackFlag::Pop);//�V�[�������j���[�ɕύX
    }
}

//�`��
void ConfigScene::draw(){
    BaseScene::draw();//�e�N���X�̕`�惁�\�b�h���Ă�
    DrawString(0, 0,"�ݒ��ʂł��B",GetColor(255,255,255));
    DrawString(0,20,"Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B",GetColor(255,255,255));
}
