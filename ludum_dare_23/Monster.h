#pragma once
#include "settings.h"
#include "Entity.h"

class Monster :
	public Entity
{
public:
	Monster(void);
	Monster(double x, double y);
	~Monster(void);

	int Draw(sf::RenderTarget * rt) const;
	int Update(void );

};

