#include "DxLib.h"
#include "SceneMgr.h"
#include "Keyboard.h"
#include "SystemData.h"

class Fps {
	int mStartTime;         //����J�n����
	int mCount;             //�J�E���^
	float mFps;             //fps
	static const int N = 60;//���ς����T���v����
	static const int FPS = 60;	//�ݒ肵��FPS

public:
	Fps() {
		mStartTime = 0;
		mCount = 0;
		mFps = 0;
	}

	bool Update() {
		if (mCount == 0) { //1�t���[���ڂȂ玞�����L��
			mStartTime = GetNowCount();
		}
		if (mCount == N) { //60�t���[���ڂȂ畽�ς��v�Z����
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
		int tookTime = GetNowCount() - mStartTime;	//������������
		int waitTime = mCount * 1000 / FPS - tookTime;	//�҂ׂ�����
		if (waitTime > 0) {
			Sleep(waitTime);	//�ҋ@
		}
	}
};

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
    SystemData::setWindowSize(800, 600);
    SystemData::setChipSize(32);

    SetGraphMode(SystemData::mWidth, SystemData::mHeight, 32);
    ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK ); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

    SceneMgr sceneMgr;
	Fps fps;
    sceneMgr.initialize();

    while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){//��ʍX�V & ���b�Z�[�W���� & ��ʏ���

		fps.Wait();
		fps.Update();	//�X�V
		fps.Draw();		//�`��
        Keyboard::update();
        sceneMgr.update();  //�X�V
        sceneMgr.draw();    //�`��

    }

    sceneMgr.finalize();

    DxLib_End(); // DX���C�u�����I������
    return 0;
}