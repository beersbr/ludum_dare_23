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
MapNode* generateMap()
{
	MapNode* rootNode = new MapNode();
	//Root of this node, BETTER BE FUCKIN' NULL
	//Lets edit the block that represents this node..
	rootNode->refBlock.dimensions.x = MAX_X_SIZE;
	rootNode->refBlock.dimensions.x = MAX_Y_SIZE;

}
