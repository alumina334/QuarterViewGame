#pragma once

#include "BaseScene.h"

enum class eMenu: int {
    Game = 0,
    Config,

    Num,
};

//���j���[��ʃN���X
class TitleScene : public BaseScene {
private:
    static eMenu mNowSelect;
public:
    TitleScene(ISceneChanger* changer);
    void initialize() override;    //�������������I�[�o�[���C�h�B
    //void finalize() override ;        //�I���������I�[�o�[���C�h�B
    void update() override;        //�X�V�������I�[�o�[���C�h�B
    void draw() override;            //�`�揈�����I�[�o�[���C�h�B

};
