#pragma once

#include "SystemData.h"

//�^�X�N�N���X�B�����̃��W���[���͂��ׂĂ���Task�N���X���p������B
class Task {
public:
    virtual ~Task(){}
    virtual void initialize(){}        //�����������͎������Ă����Ȃ��Ă�����
    virtual void finalize(){}        //�I�������͎������Ă����Ȃ��Ă�����
    virtual void update()     = 0;    //�X�V�����͕K���p����Ŏ�������
    virtual void draw()       = 0;    //�`�揈���͕K���p����Ŏ�������
};
