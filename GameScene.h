#pragma once

#include "BaseScene.h"
#include "ISceneChanger.h"
#include "MapMgr.h"

//ゲーム画面クラス
class GameScene : public BaseScene {
private:
    MapMgr mapMgr;
public :
    GameScene::GameScene(ISceneChanger* changer);
    void initialize() override;    //初期化処理をオーバーライド。
    //void finalize() override;        //終了処理をオーバーライド。
    void update() override;        //更新処理をオーバーライド。
    void draw() override;            //描画処理をオーバーライド。

};
