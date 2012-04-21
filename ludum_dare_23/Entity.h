#pragma once

#include "Vector.h"
#include "SpriteHandler.h"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity(void);
	Entity(Entity &entity);
	Entity(double x, double y);
	~Entity(void);

	virtual int Draw(sf::RenderTarget *rt) const = 0;
	virtual int Update(void ) = 0;

	SpriteHandler* spriteHandle;
	Vector2D pos;
	SpriteHandler *sprite;
};

