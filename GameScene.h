#pragma once

#include "BaseScene.h"
#include "MapMgr.h"

//�Q�[����ʃN���X
class GameScene : public BaseScene {
private:
    MapMgr* mMapMgr;
public :
    GameScene::GameScene(ISceneChanger* changer);
    void initialize() override;    //�������������I�[�o�[���C�h�B
    //void finalize() override;        //�I���������I�[�o�[���C�h�B
    void update() override;        //�X�V�������I�[�o�[���C�h�B
    void draw() override;            //�`�揈�����I�[�o�[���C�h�B

};
