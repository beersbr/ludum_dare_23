#pragma once

#include "settings.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class SpriteHandler
{
public:
	SpriteHandler(void);
	~SpriteHandler(void);

	SpriteHandler(SpriteHandler &sprite_handler);
	SpriteHandler(sf::Image *, int _frame_lag);

	int SetImage(sf::Image *, int _fram_lag);
	int SetPostition(int x, int y);
	int Draw(sf::RenderTarget *rt);

private:
	sf::Sprite sprite;

	int frame_lag; // time spent between each new image
	int frame_lag_count;
	int frames;    // the total number of frames in the image
	int current_frame; // the index of the current frame

	sf::Rect<int> rect;

	int _UpdateRectangle();
};
