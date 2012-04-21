#include "Entity.h"


Entity::Entity(void)
{
}

Entity::Entity(Entity &entity)
{
	this->pos.x = entity.pos.x;
	this->pos.y = entity.pos.y;
	this->sprite = new SpriteHandler(*entity.sprite);
}

Entity::Entity(double x, double y)
{
	this->pos.x = x;
	this->pos.y = y;
}

Entity::~Entity(void)
{
}