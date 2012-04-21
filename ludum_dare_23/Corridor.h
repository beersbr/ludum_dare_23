#pragma once
#include "settings.h"
#include "vector.h"
//#include "btMap.h"


class Corridor
{
public:
	Corridor(void);
	//Corridor(MapNode* nodeOne, MapNode* nodeTwo);
	//MapNode* nodeOne; //More or less for debugging.
	//MapNode* nodeTwo;
	Corridor* link;  //Could connect to other corridor
	Vector2D position;
	Vector2D size;
	~Corridor(void);
};

