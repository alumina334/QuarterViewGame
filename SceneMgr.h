#pragma once

#include "ISceneChanger.h"
#include "BaseScene.h"
#include <stack>
#include <memory>

class SceneMgr : public ISceneChanger, Task {

private:
    std::stack<std::shared_ptr<BaseScene>> mSceneStack; //�V�[���X�^�b�N
    eScene mNextScene;    //���̃V�[���Ǘ��ϐ�
    eStackFlag mStackFlag;
    Parameter* mParameter;

public:
    SceneMgr();
    void initialize() override;//������
    void finalize() override;//�I������
    void update() override;//�X�V
    void draw() override;//�`��

    // ���� nextScene �ɃV�[����ύX����
    void changeScene(eScene NextScene,Parameter* parameter, eStackFlag flag) override;

};