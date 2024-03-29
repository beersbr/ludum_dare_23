#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

#include "Entity.h"
#include "settings.h"
#include "Player.h"
#include "Monster.h"

class Warden
{
public:
	static Warden *instance();

	int LoadImage(std::string filename, std::string id);
	int LoadImage(std::string id, sf::Image img);
	int LoadSound(std::string filename, std::string id);
	int AddEntity(Entity* ent);

	int RemoveEntity(std::string id);
	Entity* GetEntity(std::string id);
	sf::Image *GetImage(std::string id);
	int GetSound(std::string id);

	int CheckCollisionAll();
	int DrawMap(sf::RenderTarget *rt);
	int DrawAll(sf::RenderTarget *rt);
	int UpdateAll(InputHandler *input);

private:
	Warden(void);
	~Warden(void);

	static Warden* _instance;

	static std::map<std::string, sf::Image> images;
	static std::map<std::string, sf::Sound> sounds;
	static std::vector<Entity *> entities;
	static std::map<sf::Rect<int>, std::vector<Entity *> > collision_map;
};