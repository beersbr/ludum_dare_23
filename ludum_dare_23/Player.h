#pragma once

#include "SpriteHandler.h"
#include "settings.h"
#include "Entity.h"

class Player : public Entity
{
public:
	Player(void);
	Player(double x, double y);
	~Player(void);

	int Draw(sf::RenderTarget *rt) const;
	int Update(void );

	int SetImage(sf::Image *);
};

