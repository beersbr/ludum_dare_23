#pragma once

#include "settings.h"
#include "Entity.h"

class Player : public Entity
{
public:
	Player(void);
	Player(double x, double y);
	~Player(void);

	//int Init(sf::Image *img, double start_x, double start_y);

	int Draw(sf::RenderTarget *rt) const;
	int Update(void );

	double ax, ay, friction;
};

