#pragma once

#include "BaseScene.h"

//�ݒ��ʃN���X
class ConfigScene : public BaseScene {

public :
    ConfigScene(ISceneChanger* changer);
    void initialize() override;    //�������������I�[�o�[���C�h�B
    //void finalize() override;        //�I���������I�[�o�[���C�h�B
    void update() override;        //�X�V�������I�[�o�[���C�h�B
    void draw() override;            //�`�揈�����I�[�o�[���C�h�B

};
