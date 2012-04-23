#pragma once

#include "SpriteHandler.h"
#include "InputHandler.h"
#include "settings.h"
#include "Entity.h"
#include <vector>

class Player : public Entity
{
public:
	Player(void);
	Player(double x, double y);
	~Player(void);

	int Draw(sf::RenderTarget *rt) const;
	int Update();
	int Update(InputHandler *input, std::vector<Entity *> entities);

	int SetImage(sf::Image *);
};

