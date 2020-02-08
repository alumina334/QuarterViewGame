#pragma once

#include "Parameter.h"

enum class eScene {
    Title = 0,    //���j���[���
    Config,       //�R���t�B�O���(�Q�[���O)
    Game,        //�Q�[�����
    Menu,        //���j���[���(�Q�[����)
    Edit,

    None,    //����
};

enum class eStackFlag {
    Delete = 0, //�V�[���J��(�S�폜)
    Push,         //�V�[���J��(��ԕۑ�)
    Pop,          //�V�[���J��(���̏�Ԃ�)

    None,   //����
};

//�V�[���ύX�p�C���^�[�t�F�C�X
class ISceneChanger {
public:
    virtual ~ISceneChanger() = 0;
    virtual void changeScene(eScene nextScene, Parameter* parameter, eStackFlag flag) = 0;//�w��V�[���ɕύX����
};
