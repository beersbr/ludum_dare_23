#pragma once
#include "settings.h"
#include "Entity.h"

class Item :
	public Entity
{
public:
	Item(void);
	Item(double x, double y);
	~Item(void);

	int Draw(sf::RenderTarget * rt) const;
	int Update(void );

};

