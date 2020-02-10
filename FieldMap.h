#pragma once

#include <vector>
#include "BaseMap.h"
#include "Player.h"

class FieldMap : public BaseMap {
private:
	std::vector<int> mMapChip;
	std::vector<std::vector<std::vector<int>>> mMapData;
	Player mPlayer;
public:
	FieldMap(IMapChanger* changer, Parameter* parameter);
	void initialize() override;
	void finalize() override;
	void update() override;
	void draw() override;
};