#include "DxLib.h"
#include "ConfigScene.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "SceneMgr.h"

SceneMgr::SceneMgr() : 
    mNextScene(eScene::None), mParameter(NULL), mStackFlag(eStackFlag::None){
    mSceneStack.push(std::make_shared<TitleScene>(this));
}

//初期化
void SceneMgr::initialize(){
    mSceneStack.top()->initialize();
}

//終了処理
void SceneMgr::finalize(){
    mSceneStack.top()->finalize();
}

//更新
void SceneMgr::update(){
    if (mNextScene != eScene::None) {              //次のシーンがセットされていて
        if (mStackFlag == eStackFlag::Delete) {   //スタックDeleteの場合
            while (mSceneStack.empty()) {              //スタックが空になるまで
                mSceneStack.top()->finalize();           //現在のシーンの終了処理を実行
                mSceneStack.pop();                        //削除完了
            }
        }
        if (mStackFlag != eStackFlag::Pop) { //Pop以外はPush
            std::shared_ptr<BaseScene> tmpScene;
            switch (mNextScene) {   //シーンによってインスタンスをPush
            case eScene::Title: 
                tmpScene = std::make_shared<TitleScene>(this);  
                break;
            case eScene::Game:
                tmpScene = std::make_shared<GameScene>(this);
                break;
            case eScene::Config:
                tmpScene = std::make_shared<ConfigScene>(this);
                break;
            case eScene::Menu:
                tmpScene = std::make_shared<ConfigScene>(this);
            }
            mSceneStack.push(tmpScene);
            mSceneStack.top()->initialize();    //シーンを初期化
        }
        else if(mSceneStack.size() > 1){ //Popかつ戻るシーンがある場合のみ(2以上)戻る
            mSceneStack.pop();
        }
        mNextScene = eScene::None;    //次のシーン情報をクリア
    }
    
    mSceneStack.top()->update(); //現在シーンの更新
}

//描画
void SceneMgr::draw(){
    mSceneStack.top()->draw(); //シーンの描画
}

// 引数 nextScene にシーンを変更する
void SceneMgr::changeScene(eScene nextScene, Parameter* parameter, eStackFlag flag){
    mNextScene  = nextScene;    //次のシーンをセットする
    mParameter = parameter;
    mStackFlag = flag;
}

