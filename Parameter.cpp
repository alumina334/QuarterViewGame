#include "Parameter.h"


void Parameter::set(std::string key, int val)
{
    mMap[key] = val;
}

int Parameter::get(std::string key) const
{
    auto it = mMap.find(key);//�w��L�[���擾
    if (mMap.end() == it) {//����������
        return Error;//�G���[
    }
    else {
        return it->second;//��������l��Ԃ�
    }
}