#pragma once

#include "BaseMap.h"

class FieldMap : public BaseMap {
private:
	int mMapChip;
public:
	FieldMap(IMapChanger* changer, Parameter* parameter);
	void initialize() override;
	void finalize() override;
	void update() override;
	void draw() override;
};