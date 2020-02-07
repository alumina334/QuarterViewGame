#include "GameScene.h"
#include "DxLib.h"

GameScene::GameScene(ISceneChanger* changer) : BaseScene(changer), mMapMgr() {
}

//������
void GameScene::initialize(){
    //mBGHandle = LoadGraph();    //�w�i�摜
    mMapMgr = new MapMgr();
}

//�X�V
void GameScene::update(){
    //�V�[���J��
    if(Keyboard::keyboardGet(KEY_INPUT_ESCAPE)==1){ //Esc�L�[��������Ă�����
        mSceneChanger->changeScene(eScene::Menu, NULL, eStackFlag::Delete);//�V�[�������j���[�ɕύX
    }
    //���̑�update
    mMapMgr->update();
}

//�`��
void GameScene::draw(){
    BaseScene::draw();//�e�N���X�̕`�惁�\�b�h���Ă�
    mMapMgr->draw();
    DrawString(0, 0,"�Q�[����ʂł��B",GetColor(255,255,255));
    DrawString(0,20,"Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B",GetColor(255,255,255));
}
