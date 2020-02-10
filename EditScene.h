#pragma once

#include "BaseScene.h"
#include "MapMgr.h"
#include <vector>


//�Q�[����ʃN���X
class EditScene : public BaseScene {
private:
    enum class eGraph { // �摜�f�[�^�ʂ��ԍ��H
        Frame,
        Select,
        LeftWall,
        RightWall,
        BottomWall,

        Num,
    };
    const int MAX_CHIP = 2;
    //char fileName[256];
    int mSelectX;
    int mSelectY;
    int mSelectZ;
    int mSelectBlock;
    int mMapSize;
    double mag;
    bool mBlendFlag;
    bool mSelectFlag;
    std::vector<int> mGraph;
    std::vector<int> mMapChip;
    std::vector<std::vector<std::vector<int>>> mMapData;
public:
    EditScene::EditScene(ISceneChanger* changer);
    void initialize() override;    //�������������I�[�o�[���C�h�B
    //void finalize() override;        //�I���������I�[�o�[���C�h�B
    void update() override;        //�X�V�������I�[�o�[���C�h�B
    void draw() override;            //�`�揈�����I�[�o�[���C�h�B

};
