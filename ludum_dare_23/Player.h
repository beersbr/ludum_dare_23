#pragma once

#include "Entity.h"

class Player : Entity
{
public:
	Player(void);
	~Player(void);

	int Draw(sf::RenderTarget *rt) const;
	int Update(void );
};

