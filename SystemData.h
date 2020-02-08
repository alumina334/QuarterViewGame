#pragma once

class SystemData {
private:
	SystemData();
public:
	static int mWidth;
	static int mHeight;
	static int mChipSize;

	static void setWindowSize(int width, int height);
	static void setChipSize(int chipSize);

};