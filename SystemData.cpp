#include "SystemData.h"

int SystemData::mChipSize;
int SystemData::mWidth;
int SystemData::mHeight;

SystemData::SystemData() {
}

void SystemData::setWindowSize(int width, int height) {
	mWidth = width;
	mHeight = height;
}

void SystemData::setChipSize(int chipSize) {
	mChipSize = chipSize;
}