#pragma once

#include "BaseMap.h"

class FieldMap : public BaseMap {
private:

public:
	FieldMap(IMapChanger* changer);
	void initialize() override;
	void finalize() override;
	void update() override;
	void draw() override;
};