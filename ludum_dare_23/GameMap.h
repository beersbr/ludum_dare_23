#pragma once

#include "settings.h"
#include "Warden.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

enum{GRASS = 1, DIRT, ROCK};

class GameMap
{
public:
	GameMap(void);
	~GameMap(void);

	int LoadMap(char *map);
	sf::Image GetMapImage(Warden *warden);

private:
	char **tileMap;
};

