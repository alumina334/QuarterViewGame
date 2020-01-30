#pragma once

#include "BaseScene.h"

//設定画面クラス
class ConfigScene : public BaseScene {

public :
    ConfigScene(ISceneChanger* changer);
    void initialize() override;    //初期化処理をオーバーライド。
    //void finalize() override;        //終了処理をオーバーライド。
    void update() override;        //更新処理をオーバーライド。
    void draw() override;            //描画処理をオーバーライド。

};
