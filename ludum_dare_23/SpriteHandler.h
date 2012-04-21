#pragma once

#include <SFML/Graphics.hpp>

class SpriteHandler
{
public:
	SpriteHandler(void);
	~SpriteHandler(void);

	SpriteHandler(SpriteHandler &sprite_handler);

private:
	static sf::Image Image;
	sf::Sprite Sprite;
};

