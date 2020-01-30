#include "GameScene.h"
#include "DxLib.h"

GameScene::GameScene(ISceneChanger* changer) : BaseScene(changer) {
}

//������
void GameScene::initialize(){
    //mBGHandle = LoadGraph();    //�w�i�摜
}

//�X�V
void GameScene::update(){
    if(CheckHitKey(KEY_INPUT_ESCAPE)!=0){ //Esc�L�[��������Ă�����
        mSceneChanger->changeScene(eScene::, NULL, eStackFlag::Delete);//�V�[�������j���[�ɕύX
    }
    if (FALSE) { //�G���J�E���g����
        mSceneChanger->changeScene(eScene::Battle, NULL, eStackFlag::Push);//�o�g���V�[���˓�
    }
}

//�`��
void GameScene::draw(){
    BaseScene::draw();//�e�N���X�̕`�惁�\�b�h���Ă�
    DrawString(0, 0,"�Q�[����ʂł��B",GetColor(255,255,255));
    DrawString(0,20,"Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B",GetColor(255,255,255));
}