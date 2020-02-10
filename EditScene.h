#pragma once

#include "BaseScene.h"
#include "MapMgr.h"
#include <vector>


//ゲーム画面クラス
class EditScene : public BaseScene {
private:
    enum class eGraph { // 画像データ通し番号？
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
    void initialize() override;    //初期化処理をオーバーライド。
    //void finalize() override;        //終了処理をオーバーライド。
    void update() override;        //更新処理をオーバーライド。
    void draw() override;            //描画処理をオーバーライド。

};
