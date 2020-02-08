#pragma once

#include "BaseMap.h"

class FieldMap : public BaseMap {
private:
	int mMapChip[2];
public:
	FieldMap(IMapChanger* changer);
	void initialize() override;
	void finalize() override;
	void update() override;
	void draw() override;
};