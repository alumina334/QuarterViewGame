#pragma once

#include "Parameter.h"

enum class eMap {
	FieldMap = 0,
	BattleMap,
	
	None,
};

class IMapChanger {
public:
	virtual ~IMapChanger() = 0;
	virtual void changeMap(eMap nextMap, Parameter* parameter) = 0;
};