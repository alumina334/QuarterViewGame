#pragma once

#include "Parameter.h"

enum class eScene {
    Title = 0,    //メニュー画面
    Config,       //コンフィグ画面(ゲーム外)
    Game,        //ゲーム画面
    Menu,        //メニュー画面(ゲーム内)
    Edit,

    None,    //無し
};

enum class eStackFlag {
    Delete = 0, //シーン遷移(全削除)
    Push,         //シーン遷移(状態保存)
    Pop,          //シーン遷移(元の状態へ)

    None,   //無し
};

//シーン変更用インターフェイス
class ISceneChanger {
public:
    virtual ~ISceneChanger() = 0;
    virtual void changeScene(eScene nextScene, Parameter* parameter, eStackFlag flag) = 0;//指定シーンに変更する
};
