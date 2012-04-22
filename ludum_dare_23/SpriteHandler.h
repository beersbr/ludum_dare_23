#pragma once

#include "settings.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

// Perhaps this should inherit from sf::Sprite and not wrape it... TODO

class SpriteHandler
{
public:
	SpriteHandler(void);
	~SpriteHandler(void);

	SpriteHandler(SpriteHandler &sprite_handler);
	SpriteHandler(sf::Image *, int _frame_lag = 5);

	int SetImage(sf::Image *, int _frame_lag = 5);
	int SetPostition(int x, int y, float rotation = 0.0);
	int Draw(sf::RenderTarget *rt);
	int SetCenter(int x, int y);

private:
	sf::Sprite sprite;

	int frame_lag; // time spent between each new image
	int frame_lag_count;
	int frames;    // the total number of frames in the image
	int current_frame; // the index of the current frame

	sf::Rect<int> rect;

	int _UpdateRectangle();
};
