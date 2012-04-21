#include "settings.h"
#include "btMap.h"


MapNode::MapNode()
{
	this->parent = this->left = this->right = NULL;
}

MapNode::~MapNode()
{
}

//Generates a random map and returns the root node of said map
MapNode* generateMap(int maxRooms)
{
	MapNode* rootNode = new MapNode();
	MapNode* curNode = rootNode;
	MapNode* tmpLeft, tmpRight;
	//Root of this node, <parent> BETTER BE FUCKIN' NULL
	//Lets edit the block that represents this node..
	rootNode->refBlock.dimensions.x = MAX_X_SIZE;
	rootNode->refBlock.dimensions.x = MAX_Y_SIZE;
	int numRooms;
	char curDir = 0;
	Vector2D randPos;

	//Seed that random generator
	srand(time(NULL));

	//While we don't have the desired amout of rooms...
	while(numRooms < maxRooms)
	{
		//Get a random point and direction!
		curDir = rand() % 2; //current direction.. 0 = horizontal, 1 = vertical;
		randPos.x = rand() % 100 + 1;
		randPos.y = rand() % 100 + 1;

		//split and add nodes
		tmpLeft = new MapNode();
		if(curDir) // vertical split
		{
			//Left node has same top-left pos as parent.
			tmpLeft->refBlock.position =  curNode->refBlock.position;
			//lets alter size.
		}

	}
}