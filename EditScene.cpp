#include <vector>
#include "DxLib.h"
#include "EditScene.h"


EditScene::EditScene(ISceneChanger* changer) : 
    BaseScene(changer), 
    mMapData(32, std::vector<std::vector<int>>(32, std::vector<int>(32, -1))),
    mSelectBlock(0), mBlendFlag(FALSE), mSelectFlag(FALSE)
{
    mMapChip.resize(3);
    LoadDivGraph("images/block.png", 3, 3, 1, SystemData::mChipSize, SystemData::mChipSize, &mMapChip[0]);    //背景画像のロード
    mGraph.resize((int)eGraph::Num);
    mGraph[(int)eGraph::Frame] = LoadGraph("images/block_frame.png");
    mGraph[(int)eGraph::Select] = LoadGraph("images/select_block.png");
    mGraph[(int)eGraph::LeftWall] = LoadGraph("images/left_wall.png");
    mGraph[(int)eGraph::RightWall] = LoadGraph("images/right_wall.png");
    mGraph[(int)eGraph::BottomWall] = LoadGraph("images/bottom_wall.png");
    mSelectX = 0; mSelectY = 0; mSelectZ = 0;
}

//初期化
void EditScene::initialize() {
    /*
    DrawString(0, 0, "ファイルパスを入力してください。(xxx.dat)", GetColor(255,255,255));
    KeyInputString(0, 20, 30, fileName, FALSE);
    PathFileExists(fileName);
    */
   // LoadDivGraph("images/block.png", 2, 2, 1, 32, 32, &mMapChip[0]);    //背景画像のロード
    /*
    FILE* fp;
    fopen_s(&fp, "./map/testmap.dat", "rb");
    fread(&mMapData[0], sizeof(int), 32, fp);
    fclose(fp);
    */
    
}

//更新
void EditScene::update() {
    // 終了処理
    if (Keyboard::keyboardGet(KEY_INPUT_ESCAPE) == 1) { //Escキーが押されていたら
        mSceneChanger->changeScene(eScene::Title, NULL, eStackFlag::Pop);//シーンをメニューに変更
    }
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
            if (mSelectBlock + 5 < mMapChip.size()) {
                mSelectBlock += 5;
            }
        }
        if (Keyboard::keyboardGet(KEY_INPUT_D) == 1) {
            if (mSelectBlock + 1 < mMapChip.size()) {
                mSelectBlock++;
            }
        }

    }
    else {
        // マーカー操作
        if (Keyboard::keyboardGet(KEY_INPUT_W) == 1) {
            if (mSelectY > 0) {
                mSelectY--;
            }
        }
        if (Keyboard::keyboardGet(KEY_INPUT_A) == 1) {
            if (mSelectX > 0) {
                mSelectX--;
            }
        }
        if (Keyboard::keyboardGet(KEY_INPUT_S) == 1) {
            if (mSelectY < 32) {
                mSelectY++;
            }
        }
        if (Keyboard::keyboardGet(KEY_INPUT_D) == 1) {
            if (mSelectX < 32) {
                mSelectX++;
            }
        }
        if (Keyboard::keyboardGet(KEY_INPUT_Q) == 1) {
            if (mSelectZ > 0) {
                mSelectZ--;
            }
        }
        if (Keyboard::keyboardGet(KEY_INPUT_E) == 1) {
            if (mSelectZ < 32) {
                mSelectZ++;
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
}

//描画
void EditScene::draw() {
    BaseScene::draw();//親クラスの描画メソッドを呼ぶ

    //影表示
    if (!mSelectFlag) {
        DrawBox(SystemData::mWidth / 4, 0, SystemData::mWidth, SystemData::mHeight, GetColor(40, 40, 40), TRUE); // 背景
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
    for (int z = 0; z < MAX_SIZE; z++) {
        if (mBlendFlag) {
            if (z <= mSelectZ) {
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
            }
            else if (z == mSelectZ + 1) {
                SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
            }
            else {
                break;
            }

        }
        for (int xpy = 0; xpy < MAX_SIZE*2-1; xpy++) {
            if (xpy < MAX_SIZE) {
                int y = xpy;
                for (int x = 0; x <= xpy; x++) {
                    std::vector<int> tmpHandle;
                    // ここから影表示
                    if (x == sx && y == mSelectY && z == mSelectZ) {
                        tmpHandle.push_back(mGraph[(int)eGraph::LeftWall]);
                        drawFlag = TRUE;
                    }
                    if (x == mSelectX && y == sy && z == mSelectZ) {
                        tmpHandle.push_back(mGraph[(int)eGraph::RightWall]);
                        drawFlag = TRUE;
                    }
                    if (x == mSelectX && y == mSelectY && z == sz) {
                        tmpHandle.push_back(mGraph[(int)eGraph::BottomWall]);
                        drawFlag = TRUE;
                    }
                    // ブロック表示
                    if (mMapData[z][y][x] >= 0){
                        tmpHandle.push_back(mMapChip[mMapData[z][y][x]]);
                        drawFlag = TRUE;
                        int tmpX = SystemData::mWidth * 5 / 8 + (x - y - 1) * SystemData::mChipSize / 2;
                        int tmpY = SystemData::mHeight / 2 + (x + y) * SystemData::mChipSize / 4 - SystemData::mChipSize / 2 * (z - 1);
                    }
                    // マーカー表示
                    if (x == mSelectX && y == mSelectY && z == mSelectZ) {
                        tmpHandle.push_back(mGraph[(int)eGraph::Select]);
                        drawFlag = TRUE;
                    }
                    
                    if (drawFlag) {
                        int tmpX = SystemData::mWidth * 5 / 8 + (x - y - 1) * SystemData::mChipSize / 2;
                        int tmpY = SystemData::mHeight / 2 + (x + y) * SystemData::mChipSize / 4 - SystemData::mChipSize / 2 * (z - 1);
                        for (int i = 0; i < tmpHandle.size(); i++) {
                            DrawGraph(tmpX, tmpY, tmpHandle[i], TRUE);
                        }
                        drawFlag = FALSE;
                    }
                    y--;
                }
            }
            else {
                int y = MAX_SIZE-1;
                for (int x = xpy - y; x < MAX_SIZE; x++) {
                    if (mMapData[z][y][x] >= 0) {
                        int tmpX = SystemData::mWidth * 5 / 8 + (x - y - 1) * SystemData::mChipSize / 2;
                        int tmpY = SystemData::mHeight / 2 + (x + y) * SystemData::mChipSize / 4 - SystemData::mChipSize / 2 * (z - 1);
                        DrawGraph(tmpX, tmpY, mMapChip[mMapData[z][y][x]], TRUE);
                    }
                    if (x == mSelectX && y == mSelectY && z == mSelectZ) {
                        int tmpX = SystemData::mWidth * 5 / 8 + (x - y - 1) * SystemData::mChipSize / 2;
                        int tmpY = SystemData::mHeight / 2 + (x + y) * SystemData::mChipSize / 4 - SystemData::mChipSize / 2 * (z - 1);
                        DrawGraph(tmpX, tmpY, mGraph[(int)eGraph::Select], TRUE);
                    }
                    y--;
                }
            }
        }
    }
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

    DrawFormatString(SystemData::mWidth / 4 + SystemData::mWidth / 80, SystemData::mHeight / 60, GetColor(255, 255, 255), "X:%d Y:%d Z:%d", mSelectX, mSelectY, mSelectZ);
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
