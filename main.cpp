#include "DxLib.h"
#include "SceneMgr.h"
#include "Keyboard.h"
#include "SystemData.h"

class Fps {
	int mStartTime;         //測定開始時刻
	int mCount;             //カウンタ
	float mFps;             //fps
	static const int N = 60;//平均を取るサンプル数
	static const int FPS = 60;	//設定したFPS

public:
	Fps() {
		mStartTime = 0;
		mCount = 0;
		mFps = 0;
	}

	bool Update() {
		if (mCount == 0) { //1フレーム目なら時刻を記憶
			mStartTime = GetNowCount();
		}
		if (mCount == N) { //60フレーム目なら平均を計算する
			int t = GetNowCount();
			mFps = 1000.f / ((t - mStartTime) / (float)N);
			mCount = 0;
			mStartTime = t;
		}
		mCount++;
		return true;
	}

	void Draw() {
		DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", mFps);
	}

	void Wait() {
		int tookTime = GetNowCount() - mStartTime;	//かかった時間
		int waitTime = mCount * 1000 / FPS - tookTime;	//待つべき時間
		if (waitTime > 0) {
			Sleep(waitTime);	//待機
		}
	}
};

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
    SystemData::setWindowSize(800, 600);
    SystemData::setChipSize(32);

    SetGraphMode(SystemData::mWidth, SystemData::mHeight, 32);
    ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK ); //ウィンドウモード変更と初期化と裏画面設定

    SceneMgr sceneMgr;
	Fps fps;
    sceneMgr.initialize();

    while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){//画面更新 & メッセージ処理 & 画面消去

		fps.Wait();
		fps.Update();	//更新
		fps.Draw();		//描画
        Keyboard::update();
        sceneMgr.update();  //更新
        sceneMgr.draw();    //描画

    }

    sceneMgr.finalize();

    DxLib_End(); // DXライブラリ終了処理
    return 0;
}