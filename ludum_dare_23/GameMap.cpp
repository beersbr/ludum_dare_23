#include "GameMap.h"

GameMap::GameMap(void)
{
	(this->tileMap) = new char*[MAX_Y_SIZE];
	for(int i = 0; i < MAX_X_SIZE; i++)
	{
		(this->tileMap)[i] = new char[MAX_X_SIZE];
	}
}

GameMap::~GameMap(void)
{
	for(int i = 0; i < MAX_X_SIZE; i++)
	{
		delete (this->tileMap)[i];
	}
	delete (this->tileMap);
}
