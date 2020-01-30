#include "DxLib.h"
#include "SceneMgr.h"
#include "Keyboard.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
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