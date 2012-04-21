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

class Warden
{
public:
	static Warden *instance();

	int LoadImage(std::string filename, std::string id);
	int LoadSound(std::string filename, std::string id);
	int AddEntity(std::string id, Entity* entity);
	
	int RemoveEntity(std::string id);
	Entity* GetEntity(std::string id);
	sf::Image *GetImage(std::string id);
	int GetSound(std::string id);

private:
	Warden(void);
	~Warden(void);

	static Warden* _instance;

	static std::map<std::string, sf::Image> images;
	static std::map<std::string, sf::Sound> sounds;
	static std::map<std::string, Entity*> entities;
};