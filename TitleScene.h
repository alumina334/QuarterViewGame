#pragma once

#include "BaseScene.h"

enum class eTitle: int {
    Game = 0,
    Config,
    Edit,

    Num,
};

//メニュー画面クラス
class TitleScene : public BaseScene {
private:
    static eTitle mNowSelect;
public:
    TitleScene(ISceneChanger* changer);
    void initialize() override;    //初期化処理をオーバーライド。
    //void finalize() override ;        //終了処理をオーバーライド。
    void update() override;        //更新処理をオーバーライド。
    void draw() override;            //描画処理をオーバーライド。

};
