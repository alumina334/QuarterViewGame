
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "DxLib.h"
#include "EditScene.h"


EditScene::EditScene(ISceneChanger* changer) : 
    BaseScene(changer), 
    mMapData(32, std::vector<std::vector<int>>(32, std::vector<int>(32, -1))),
    mMapChip(0, 0), mSelectBlock(0), mBlendFlag(FALSE), mSelectFlag(FALSE), mag(1),
    mSelectX(0), mSelectY(0), mSelectZ(0), mMapSize(32)
{
    mMapChip.resize(3);
    LoadDivGraph("images/block.png", 3, 3, 1, SystemData::mChipSize, SystemData::mChipSize, &mMapChip[0]);    //背景画像のロード

    mGraph.resize((int)eGraph::Num);
    mGraph[(int)eGraph::Frame] = LoadGraph("images/block_frame.png");
    mGraph[(int)eGraph::Select] = LoadGraph("images/select_block.png");
    mGraph[(int)eGraph::LeftWall] = LoadGraph("images/left_wall.png");
    mGraph[(int)eGraph::RightWall] = LoadGraph("images/right_wall.png");
    mGraph[(int)eGraph::BottomWall] = LoadGraph("images/bottom_wall.png");
}

//初期化
void EditScene::initialize() {
    // ファイル読み込み
    char fileName[256];
    DrawString(10, 10, "読み込むファイル名(xxxx)を入力してください。./map/\"xxxx\".dat (Escで新規作成)", GetColor(255, 255, 255));
    int res = KeyInputString(10, 30, 256, fileName, TRUE);
    std::string fstring = "./map/" + std::string(fileName) + ".dat";

    if (res == 1) { // 入力があった場合
        FILE* fp;
        errno_t error;
        error = fopen_s(&fp, fstring.c_str(), "rb");
        if (error != 0) {
            DrawString(10, 50, "ファイルが開けませんでした。", GetColor(255, 255, 255));
            this->initialize();
        }
        else {
            fread(&mMapSize, sizeof(int), 1, fp);
            for (int z = 0; z < mMapSize; z++) {
                for (int y = 0; y < mMapSize; y++) {
                    for (int x = 0; x < mMapSize; x++) {
                        fread(&mMapData[z][y][x], sizeof(int), 1, fp);
                    }
                }
            }
            fclose(fp);
        }
    }
    Keyboard::setNum(KEY_INPUT_ESCAPE, 2);
}

//更新
void EditScene::update() {
    // 終了処理
    if (Keyboard::keyboardGet(KEY_INPUT_ESCAPE) == 1) { //Escキーが押されていたら
        // マップデータ書き込み
        char fileName[256];
        DrawString(10, 10, "保存ファイル名(xxxx)を入力してください。./map/\"xxxx\".dat  (Escでキャンセル)", GetColor(255, 255, 255));
        
        int res = KeyInputString(10, 30, 256, fileName,TRUE);
        std::string fstring = "./map/" + std::string(fileName) + ".dat";
        if (res == 1) {
            FILE* fp;
            fopen_s(&fp, fstring.c_str(), "wb");
            //　ヘッダ情報 
            int size = 32;
            fwrite(&size, sizeof(int), 1, fp);
            for each (std::vector<std::vector<int>> vv in mMapData) {
                for each (std::vector<int> v in vv) {
                    for each (int elem in v) {
                        fwrite(&elem, sizeof(int), 1, fp);
                    }
                }
            }
            fclose(fp);
            mSceneChanger->changeScene(eScene::Title, NULL, eStackFlag::Pop);//シーンをメニューに変更
            Keyboard::setNum(KEY_INPUT_RETURN, 2);
        }
        else if (res == 2) {
            
        }
    }
    // 編集モード
    if(mSelectFlag){
        if (Keyboard::keyboardGet(KEY_INPUT_W) == 1) {
            if (mSelectBlock - 5 >= 0) {
                mSelectBlock -= 5;
            }
        }
        if (Keyboard::keyboardGet(KEY_INPUT_A) == 1) {
            if (mSelectBlock - 1 >= 0) {
                mSelectBlock--;
            }
        }
        if (Keyboard::keyboardGet(KEY_INPUT_S) == 1) {
            if ((unsigned)mSelectBlock + 5 < mMapChip.size()) {
                mSelectBlock += 5;
            }
        }
        if (Keyboard::keyboardGet(KEY_INPUT_D) == 1) {
            if ((unsigned)mSelectBlock + 1 < mMapChip.size()) {
                mSelectBlock++;
            }
        }

    }
    else {
        // マーカー操作
        if (Keyboard::keyboardGet(KEY_INPUT_W) == 1) {
            if (mSelectZ > 0) {
                mSelectZ--;
            }
        }
        if (Keyboard::keyboardGet(KEY_INPUT_A) == 1) {
            if (mSelectY > 0) {
                mSelectY--;
            }
        }
        if (Keyboard::keyboardGet(KEY_INPUT_S) == 1) {
            if (mSelectZ < 31) {
                mSelectZ++;
            }
        }
        if (Keyboard::keyboardGet(KEY_INPUT_D) == 1) {
            if (mSelectY < 31) {
                mSelectY++;
            }
        }
        if (Keyboard::keyboardGet(KEY_INPUT_Q) == 1) {
            if (mSelectX > 0) {
                mSelectX--;
            }
        }
        if (Keyboard::keyboardGet(KEY_INPUT_E) == 1) {
            if (mSelectX < 31) {
                mSelectX++;
            }
        }
        // ブロック設置
        if (Keyboard::keyboardGet(KEY_INPUT_RETURN) == 1) {
            mMapData[mSelectZ][mSelectY][mSelectX] = mSelectBlock;
        }
        if (Keyboard::keyboardGet(KEY_INPUT_BACK) == 1) {
            mMapData[mSelectZ][mSelectY][mSelectX] = -1;
        }
    }
    // ブロック選択
    if (Keyboard::keyboardGet(KEY_INPUT_TAB) == 1) {
        mSelectFlag = !mSelectFlag;
    }
    // ブレンドモード
    if (Keyboard::keyboardGet(KEY_INPUT_LCONTROL) == 1) {
        mBlendFlag = !mBlendFlag;
    }
    // 拡縮率
    if (Keyboard::keyboardGet(KEY_INPUT_UP) == 1) {
        mag += 0.1;
    }
    else if (Keyboard::keyboardGet(KEY_INPUT_DOWN) == 1) {
        mag -= 0.1;
    }


}

//描画
void EditScene::draw() {
    BaseScene::draw();//親クラスの描画メソッドを呼ぶ

    //影表示
    if (!mSelectFlag) {
        DrawBox(200, 0, 800, 600, GetColor(40, 40, 40), TRUE); // 背景
    }
    int sx=0, sy=0, sz=0;
    for (int x = mSelectX-1; x >= 0; x--) {
        if (mMapData[mSelectZ][mSelectY][x] >= 0) {
            sx = x+1;
            break;
        }
    }
    for (int y = mSelectY-1; y >= 0; y--) {
        if (mMapData[mSelectZ][y][mSelectX] >= 0) {
            sy = y+1;
            break;
        }
    }
    for (int z = mSelectZ-1; z >= 0; z--) {
        if (mMapData[z][mSelectY][mSelectX] >= 0) {
            sz = z+1;
            break;
        }
    }
    // マップ後ろから順に表示
    bool drawFlag = FALSE;
    std::vector<int> tmpHandle;
    for (int z = 0; z < mMapSize; z++) {
        for (int y = 0; y < mMapSize; y++) {
            for (int x = 0; x < mMapSize; x++) {
                if (mBlendFlag) {
                    if (x == mSelectX+1) {
                        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 40);
                    }
                    else if (x <= mSelectX) {
                        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
                    }
                    else {
                        break;
                    }
                }
                tmpHandle.clear();
                // ここから影表示
                if (x == sx && y == mSelectY && z == mSelectZ) {
                    tmpHandle.push_back(mGraph[(int)eGraph::BottomWall]);
                    drawFlag = TRUE;
                }
                if (x == mSelectX && y == sy && z == mSelectZ) {
                    tmpHandle.push_back(mGraph[(int)eGraph::LeftWall]);
                    drawFlag = TRUE;
                }
                if (x == mSelectX && y == mSelectY && z == sz) {
                    tmpHandle.push_back(mGraph[(int)eGraph::RightWall]);
                    drawFlag = TRUE;
                }
                // ブロック表示
                if (mMapData[z][y][x] >= 0) {
                    tmpHandle.push_back(mMapChip[mMapData[z][y][x]]);
                    drawFlag = TRUE;
                }
                // マーカー表示
                if (x == mSelectX && y == mSelectY && z == mSelectZ) {
                    tmpHandle.push_back(mGraph[(int)eGraph::Select]);
                    drawFlag = TRUE;
                }

                if (drawFlag) {
                    int tmpX = 500 + (y - mSelectY - z + mSelectZ - 1) * SystemData::mChipSize / 2 * mag;
                    int tmpY = 300 + (y - mSelectY + z - mSelectZ) * SystemData::mChipSize / 4 * mag - (x - mSelectX - 1) * SystemData::mChipSize / 2 * mag;
                    for (unsigned int i = 0; i < tmpHandle.size(); i++) {
                        DrawExtendGraph(tmpX, tmpY, tmpX + SystemData::mChipSize * mag, tmpY + SystemData::mChipSize * mag, tmpHandle[i], TRUE);
                    }
                    drawFlag = FALSE;
                }
            }
        }
    }
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

    DrawFormatString(SystemData::mWidth / 4 + SystemData::mWidth / 80, SystemData::mHeight / 60, GetColor(255, 255, 255), "X:%d Y:%d Z:%d  %.0lf%%", mSelectX, mSelectY, mSelectZ, mag*100);
    if (mBlendFlag) DrawFormatString(SystemData::mWidth / 4 + SystemData::mWidth / 80, SystemData::mHeight * 3 / 60, GetColor(255, 255, 255), "透過モード：ON");
    else DrawFormatString(SystemData::mWidth / 4 + SystemData::mWidth / 80, SystemData::mHeight * 3 / 60, GetColor(255, 255, 255), "透過モード：OFF");
    DrawFormatString(SystemData::mWidth / 4 + SystemData::mWidth / 80, SystemData::mHeight * 53 / 60, GetColor(255, 255, 255), "A: 左上　W: 右上　TAB: 編集モード切替　CTRL: 透過モード切替");
    DrawFormatString(SystemData::mWidth / 4 + SystemData::mWidth / 80, SystemData::mHeight * 55 / 60, GetColor(255, 255, 255), "S: 左下　D: 右下　ENTER: 設置");
    DrawFormatString(SystemData::mWidth / 4 + SystemData::mWidth / 80, SystemData::mHeight * 57 / 60, GetColor(255, 255, 255), "E: 上　Q: 下　BACK: 削除");
   
    // マップチップリスト表示
    if (mSelectFlag) {
        DrawBox(0, 0, SystemData::mWidth / 4, SystemData::mHeight, GetColor(40, 40, 40), TRUE); // 背景
        DrawBox(1, 1, SystemData::mWidth / 4 - 1, SystemData::mHeight - 1, GetColor(255, 255, 255), FALSE);
    }
    else {
        DrawBox(SystemData::mWidth/4 +1, 1, SystemData::mWidth-1, SystemData::mHeight-1, GetColor(255, 255, 255), FALSE);
    }
    for (int i = 0; i < 3; i++) {
        int tmpX = SystemData::mWidth / 80 + (SystemData::mWidth * 9 / 40 - SystemData::mChipSize) / 4 * (i % 5);
        int tmpY = SystemData::mHeight / 60 + (SystemData::mWidth * 9 / 40 - SystemData::mChipSize) / 4 * (i / 5);
        DrawGraph(tmpX, tmpY, mMapChip[i], TRUE);
    }
    int tmpX = SystemData::mWidth / 80 + (SystemData::mWidth * 9 / 40 - SystemData::mChipSize) / 4 * (mSelectBlock % 5);
    int tmpY = SystemData::mHeight / 60 + (SystemData::mWidth * 9 / 40 - SystemData::mChipSize) / 4 * (mSelectBlock / 5);
    DrawGraph(tmpX - 2, tmpY - 2, mGraph[(int)eGraph::Frame], TRUE);
    
    
}
