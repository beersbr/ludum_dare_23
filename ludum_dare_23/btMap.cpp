#include "settings.h"
#include "btMap.h"


MapNode::MapNode()
{
	this->parent = this->left = this->right = NULL;
}

MapNode* generateMapTree(int maxRooms)
{
	MapNode* rootNode = new MapNode();

	rootNode->refBlock.dimensions.x = MAX_X_SIZE;
	rootNode->refBlock.dimensions.y = MAX_Y_SIZE;
	rootNode->refBlock.position.x = 0;
	rootNode->refBlock.position.y = 0;
	generateMapHelper(rootNode, 1, maxRooms);
	return rootNode;
}
	

//Generates a random map and returns the root node of said map
void generateMapHelper(MapNode* curNode, int curRooms, int maxRooms)
{
	MapNode* tmpLeft;
	MapNode* tmpRight;
	//Root of this node, <parent> BETTER BE FUCKIN' NULL
	//Lets edit the block that represents this node..

	if(curRooms > maxRooms)
	{
		return;
	}

	char curDir = 0;
	Vector2D randPos;

	//Seed that random generator
	srand(time(NULL));

	//Get a random point and direction!
	curDir = rand() % 2; //current direction.. 0 = horizontal, 1 = vertical;
	randPos.x = rand() % 100 + 1;
	randPos.y = rand() % 100 + 1;

	//split and add nodes
	tmpLeft = new MapNode();
	tmpRight = new MapNode();

	if(curDir) // vertical split
	{
		//Left node has same top-left pos as parent.
		tmpLeft->refBlock.position =  curNode->refBlock.position;
		//lets alter size -> only X on vertical splits
		tmpLeft->refBlock.dimensions = curNode->refBlock.dimensions;
		tmpLeft->refBlock.dimensions.x = curNode->refBlock.dimensions.x - randPos.x;
			
		//right node is equal to split x pos
		tmpRight->refBlock.position.x = randPos.x;
		tmpRight->refBlock.position.y = curNode->refBlock.position.y; //just in case

		tmpRight->refBlock.dimensions.y = curNode->refBlock.dimensions.y;
		tmpRight->refBlock.dimensions.x = curNode->refBlock.dimensions.x - tmpLeft->refBlock.dimensions.x; //Right gets what space is left
	}
	else //Horizontal split
	{
		//left still has top left as parent
		tmpLeft->refBlock.position = curNode->refBlock.position;
		//size changes in y
		tmpLeft->refBlock.dimensions = curNode->refBlock.dimensions;
		tmpLeft->refBlock.dimensions.y = curNode->refBlock.dimensions.y - randPos.y;

		//Right node is at the split position

		tmpRight->refBlock.position.x = curNode->refBlock.position.x;
		tmpRight->refBlock.position.y = randPos.y;

		tmpRight->refBlock.dimensions.x = curNode->refBlock.dimensions.x;
		tmpRight->refBlock.dimensions.y = curNode->refBlock.dimensions.y - tmpLeft->refBlock.dimensions.y; //Right takes the rest.
	}
	tmpLeft->parent = curNode;
	tmpRight->parent = curNode;
	curNode->left = tmpLeft;
	curNode->right = tmpRight;
	//left
	generateMapHelper(curNode->left, curRooms + 2, maxRooms /2);
	generateMapHelper(curNode->right, curRooms + 2, maxRooms /2);

	
}