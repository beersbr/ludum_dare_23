#pragma once

#include "settings.h"

#include <SFML/Graphics.hpp>

class SpriteHandler
{
public:
	SpriteHandler(void);
	~SpriteHandler(void);

	SpriteHandler(SpriteHandler &sprite_handler);
	SpriteHandler(sf::Image *);

	int GetImage(sf::Image *);

	int Draw(sf::RenderTarget *rt);

private:
	sf::Sprite sprite;

	int frames;
	int current_frame;

};

