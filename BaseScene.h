#pragma once

#include "Task.h"
#include "ISceneChanger.h"
#include "Keyboard.h"

//シーンの基底クラス。
class BaseScene : public Task {
protected:
    int mBGHandle;                //画像ハンドル格納用変数
    ISceneChanger* mSceneChanger;    //クラス所有元にシーン切り替えを伝えるインターフェイス
public :
    BaseScene(ISceneChanger* changer);
    virtual ~BaseScene(){}
    virtual void initialize() override {}    //初期化処理をオーバーライド。
    virtual void finalize() override ;        //終了処理をオーバーライド。
    virtual void update() override {}        //更新処理をオーバーライド。
    virtual void draw() override ;            //描画処理をオーバーライド。

};
