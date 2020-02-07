#pragma once

#include "Task.h"
#include "ISceneChanger.h"
#include "Keyboard.h"

//�V�[���̊��N���X�B
class BaseScene : public Task {
protected:
    int mBGHandle;                //�摜�n���h���i�[�p�ϐ�
    ISceneChanger* mSceneChanger;    //�N���X���L���ɃV�[���؂�ւ���`����C���^�[�t�F�C�X
public :
    BaseScene(ISceneChanger* changer);
    virtual ~BaseScene(){}
    virtual void initialize() override {}    //�������������I�[�o�[���C�h�B
    virtual void finalize() override ;        //�I���������I�[�o�[���C�h�B
    virtual void update() override {}        //�X�V�������I�[�o�[���C�h�B
    virtual void draw() override ;            //�`�揈�����I�[�o�[���C�h�B

};
