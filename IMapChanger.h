#pragma once

enum class eMap {
	Map1 = 0,

	None,
};

class IMapChanger {
public:
	virtual ~IMapChanger() = 0;
	virtual void changeMap(eMap nextMap) = 0;
};