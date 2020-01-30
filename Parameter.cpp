#include "Parameter.h"


void Parameter::set(std::string key, int val)
{
    mMap[key] = val;
}

int Parameter::get(std::string key) const
{
    auto it = mMap.find(key);//指定キーを取得
    if (mMap.end() == it) {//無かったら
        return Error;//エラー
    }
    else {
        return it->second;//あったら値を返す
    }
}