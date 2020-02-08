#include "DxLib.h"
#include "SceneMgr.h"
#include "Keyboard.h"
#include "SystemData.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
    SystemData::setWindowSize(800, 600);
    SystemData::setChipSize(32);

    SetGraphMode(SystemData::mWidth, SystemData::mHeight, 32);
    ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK ); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

    SceneMgr sceneMgr;
    sceneMgr.initialize();

    while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){//��ʍX�V & ���b�Z�[�W���� & ��ʏ���

        Keyboard::update();
        sceneMgr.update();  //�X�V
        sceneMgr.draw();    //�`��

    }

    sceneMgr.finalize();

    DxLib_End(); // DX���C�u�����I������
    return 0;
}