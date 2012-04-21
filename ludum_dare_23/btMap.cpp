#include "settings.h"
#include "btMap.h"


MapNode::MapNode()
{
	this->parent = this->left = this->right = NULL;
}

MapNode* generateMapTree(int maxRooms)
{
	MapNode* rootNode = new MapNode();
	std::vector<MapNode*>* leafList = new std::vector<MapNode*>();

	rootNode->refBlock.dimensions.x = MAX_X_SIZE;
	rootNode->refBlock.dimensions.y = MAX_Y_SIZE;
	rootNode->refBlock.position.x = 0;
	rootNode->refBlock.position.y = 0;
	generateMapHelper(rootNode, 1, maxRooms);
	
	//Now we need to create rooms in the leaves.
	getLeafNodes(rootNode, leafList);

	//for each leaf node...
	for(int i = 0; i < leafList->size(); i++)
	{
		//generate a room somewhere in this node.
		generateRoom((*leafList)[i]);
	}

	//Connect some corridors
	for(int i = 0; i < leafList->size(); i+=2)
	{
		//connect the two nodes together
		connectRooms((*leafList)[i], (*leafList)[i+1]);
	}
}

void connectRooms(MapNode* roomOne, MapNode* roomTwo)
{

}
	
void generateRoom(MapNode* blockNode)
{
	//figure out a random spot, with a random size.
	//If there's no way this is gonna fit, create a smaller map

	int roomSize = rand() % MAX_ROOM_SIZE + MIN_ROOM_SIZE;
	
	//check to see if the room is bigger than the block
	while(roomSize > blockNode->refBlock.dimensions.x || roomSize > blockNode->refBlock.dimensions.y)
	{
		roomSize = rand() % MAX_ROOM_SIZE + MIN_ROOM_SIZE;
	}

	//pick a position (top left corner)
	Vector2D roomPos(rand() % (int)( blockNode->refBlock.blockX() + blockNode->refBlock.blockWidth() ) + blockNode->refBlock.blockX() ,  rand() % (int)( blockNode->refBlock.blockY() + blockNode->refBlock.blockHeight()) + blockNode->refBlock.blockY());
	//That was long.. let's check to see if it fits..
	while(roomPos.x > (blockNode->refBlock.blockX() + blockNode->refBlock.blockWidth()) && roomPos.y > (blockNode->refBlock.blockY() + blockNode->refBlock.blockHeight()))
	{
		roomPos.x = rand() % (int)( blockNode->refBlock.blockX() + blockNode->refBlock.blockWidth() ) + blockNode->refBlock.blockX();
		roomPos.y = rand() % (int)( blockNode->refBlock.blockY() + blockNode->refBlock.blockHeight()) + blockNode->refBlock.blockY();
	}
	//TODO: Check for fitting in the other direction, maybe

	//room is placed!
	Room tmpRoom(roomPos, roomSize);
	blockNode->refRoom = tmpRoom;
	
}

void getLeafNodes(MapNode* rootNode, std::vector<MapNode*>* leaves)
{
	if(rootNode == NULL)
	{
		//we wen't too deep
		return;
	}

	if(rootNode->left == NULL && rootNode->right == NULL)
	{
		//its a leaf, add it.
		leaves->push_back(rootNode);
		return;
	}

	getLeafNodes(rootNode->left, leaves);
	getLeafNodes(rootNode->right, leaves);
	return;
}

	


//Generates a random map and returns the root node of said map
void generateMapHelper(MapNode* curNode, int curDepth, int maxDepth)
{
	MapNode* tmpLeft;
	MapNode* tmpRight;
	//Root of this node, <parent> BETTER BE FUCKIN' NULL
	//Lets edit the block that represents this node..

	if(curDepth >= maxDepth)
	{
		return;
	}

	char curDir = 0;
	Vector2D randPos;

	//Seed that random generator
	srand(time(NULL));

	//Get a random point and direction!
	curDir = rand() % 2; //current direction.. 0 = horizontal, 1 = vertical;
	randPos.x = rand() % MAX_X_SIZE + 1;
	randPos.y = rand() % MAX_Y_SIZE + 1;


	while(MAX_X_SIZE - randPos.x < 5 || MAX_Y_SIZE - randPos.y < 5)
	{
		randPos.x = rand() % MAX_X_SIZE + 1;
		randPos.y = rand() % MAX_Y_SIZE + 1;
	}

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
	generateMapHelper(curNode->left, curDepth+1, maxDepth);
	generateMapHelper(curNode->right, curDepth+1, maxDepth);	
}

//Flatten out the Map file.
char* generateMap(int maxRooms)
{

}