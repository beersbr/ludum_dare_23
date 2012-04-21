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

sf::Image GameMap::GetMapImage(Warden *warden)
{
	sf::Image mapImage;
	mapImage.Create(MAX_X_SIZE * X_TILE_SIZE, MAX_Y_SIZE * Y_TILE_SIZE, sf::Color(0, 0, 0));

	for(int i = 0; i < MAX_Y_SIZE; i++)
	{
		for(int j = 0; j < MAX_X_SIZE; j++)
		{
			
		}
	}
}