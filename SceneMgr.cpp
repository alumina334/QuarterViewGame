#include "DxLib.h"
#include "ConfigScene.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "SceneMgr.h"

SceneMgr::SceneMgr() : 
    mNextScene(eScene::None), mParameter(NULL), mStackFlag(eStackFlag::None){
    mSceneStack.push(std::make_shared<TitleScene>(this));
}

//������
void SceneMgr::initialize(){
    mSceneStack.top()->initialize();
}

//�I������
void SceneMgr::finalize(){
    mSceneStack.top()->finalize();
}

//�X�V
void SceneMgr::update(){
    if (mNextScene != eScene::None) {              //���̃V�[�����Z�b�g����Ă���
        if (mStackFlag == eStackFlag::Delete) {   //�X�^�b�NDelete�̏ꍇ
            while (mSceneStack.empty()) {              //�X�^�b�N����ɂȂ�܂�
                mSceneStack.top()->finalize();           //���݂̃V�[���̏I�����������s
                mSceneStack.pop();                        //�폜����
            }
        }
        if (mStackFlag != eStackFlag::Pop) { //Pop�ȊO��Push
            std::shared_ptr<BaseScene> tmpScene;
            switch (mNextScene) {   //�V�[���ɂ���ăC���X�^���X��Push
            case eScene::Title: 
                tmpScene = std::make_shared<TitleScene>(this);  
                break;
            case eScene::Game:
                tmpScene = std::make_shared<GameScene>(this);
                break;
            case eScene::Config:
                tmpScene = std::make_shared<ConfigScene>(this);
                break;
            case eScene::Menu:
                tmpScene = std::make_shared<ConfigScene>(this);
            }
            mSceneStack.push(tmpScene);
            mSceneStack.top()->initialize();    //�V�[����������
        }
        else if(mSceneStack.size() > 1){ //Pop���߂�V�[��������ꍇ�̂�(2�ȏ�)�߂�
            mSceneStack.pop();
        }
        mNextScene = eScene::None;    //���̃V�[�������N���A
    }
    
    mSceneStack.top()->update(); //���݃V�[���̍X�V
}

//�`��
void SceneMgr::draw(){
    mSceneStack.top()->draw(); //�V�[���̕`��
}

// ���� nextScene �ɃV�[����ύX����
void SceneMgr::changeScene(eScene nextScene, Parameter* parameter, eStackFlag flag){
    mNextScene  = nextScene;    //���̃V�[�����Z�b�g����
    mParameter = parameter;
    mStackFlag = flag;
}

