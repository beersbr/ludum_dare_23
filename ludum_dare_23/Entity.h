#pragma once

#include "Vector.h"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity(void);
	~Entity(void);

	virtual int Draw(sf::RenderTarget *rt) const = 0;
	virtual int Update(void ) = 0;

	Vector2D pos;
};

