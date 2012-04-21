#pragma once

#include "settings.h"
#include "Vector.h"
#include "Block.h"


class MapNode
{
public:
	MapNode();
	~MapNode();
	Block refBlock;
	MapNode* parent;
	MapNode* left;
	MapNode* right;

};

//Generates a random map and returns the root node of said map
MapNode* generateMapTree(int maxRooms);
void generateMapHelper(MapNode* curNode, int curRooms, int maxRooms);