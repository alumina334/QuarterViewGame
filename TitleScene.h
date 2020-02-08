#pragma once

#include "BaseScene.h"

enum class eTitle: int {
    Game = 0,
    Config,
    Edit,

    Num,
};

//���j���[��ʃN���X
class TitleScene : public BaseScene {
private:
    static eTitle mNowSelect;
public:
    TitleScene(ISceneChanger* changer);
    void initialize() override;    //�������������I�[�o�[���C�h�B
    //void finalize() override ;        //�I���������I�[�o�[���C�h�B
    void update() override;        //�X�V�������I�[�o�[���C�h�B
    void draw() override;            //�`�揈�����I�[�o�[���C�h�B

};
