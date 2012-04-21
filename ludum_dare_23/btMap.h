#pragma once

#include "settings.h"
#include "Vector.h"
#include "Block.h"
#include "Room.h"


#include <vector>

class MapNode
{
public:
	MapNode();
	~MapNode();
	Block refBlock;
	Room  refRoom;
	MapNode* parent;
	MapNode* left;
	MapNode* right;

};

//Generates a random map and returns the root node of said map
MapNode* generateMapTree(int maxRooms);
void generateMapHelper(MapNode* curNode, int curRooms, int maxRooms);
char* generateMap(int maxRooms);
void generateRoom(MapNode* blockNode);
void getLeafNodes(MapNode* rootNode, std::vector<MapNode*>* leaves);
void connectRooms(MapNode* roomOne, MapNode* roomTwo);