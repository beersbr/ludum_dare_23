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
	virtual bool HasCollision(Entity *) const;

	int SetZindex(int idx);
	bool operator<(Entity *);
	sf::Vector2<int> GetCenter();

	Vector2D pos;
	SpriteHandler *sprite;
	double ax, ay, friction;
	float curRotation;
	int zindex;

	ENTITY_TYPE type;
};

