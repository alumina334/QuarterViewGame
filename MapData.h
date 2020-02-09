#pragma once

#include <vector>

enum class eChipSet {
	Default,

	Num,
};

class MapData {
private:
	std::vector<std::vector<std::vector<int>>> mMapData;
	eChipSet mChipSet;
	int mMapSize;
	int mChipSize;
public:
	void drawMap();
};