#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <map>
#include <vector>

class Warden
{
public:
	Warden(void);
	~Warden(void);

	int AddImage(std::string filename);
	int AddSound(std::string filename);
	
private:
	std::map<std::string, sf::Image> images;
	std::vector<std::string, sf::AudioResource> sounds;
};