#include "DxLib.h"
#include "SceneMgr.h"
#include "Keyboard.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
    ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK ); //ウィンドウモード変更と初期化と裏画面設定

    SceneMgr sceneMgr;
    sceneMgr.initialize();

    while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){//画面更新 & メッセージ処理 & 画面消去

        Keyboard::update();
        sceneMgr.update();  //更新
        sceneMgr.draw();    //描画

    }

    sceneMgr.finalize();

    DxLib_End(); // DXライブラリ終了処理
    return 0;
}