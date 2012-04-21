#pragma once

#include "settings.h"

class GameMap
{
public:
	GameMap(void);
	~GameMap(void);

	int LoadMap(char *map);

private:
	char **tileMap;
};

