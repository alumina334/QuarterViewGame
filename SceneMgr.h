#pragma once

#include "ISceneChanger.h"
#include "BaseScene.h"
#include <stack>
#include <memory>

class SceneMgr : public ISceneChanger, Task {

private:
    std::stack<std::shared_ptr<BaseScene>> mSceneStack; //シーンスタック
    eScene mNextScene;    //次のシーン管理変数
    eStackFlag mStackFlag;
    Parameter* mParameter;

public:
    SceneMgr();
    void initialize() override;//初期化
    void finalize() override;//終了処理
    void update() override;//更新
    void draw() override;//描画

    // 引数 nextScene にシーンを変更する
    void changeScene(eScene NextScene,Parameter* parameter, eStackFlag flag) override;

};