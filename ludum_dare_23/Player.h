#pragma once

#include "settings.h"
#include "Entity.h"

class Player : Entity
{
public:
	Player(void);
	Player(double x, double y);
	~Player(void);

	int Draw(sf::RenderTarget *rt) const;
	int Update(void );
};

