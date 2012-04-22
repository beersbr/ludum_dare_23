#include "Entity.h"


Entity::Entity(void)
{
	this->pos.x = 0;
	this->pos.y = 0;
	this->ax = 0, this->ay = 0;
	this->friction = 0.88;
	this->curRotation = 0.0;
	this->sprite = new SpriteHandler();
	this->zindex = 0;
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
	this->ax = 0, this->ay = 0;
	this->friction = 0.88;
	this->curRotation = 0.0;
	this->sprite = new SpriteHandler();
	this->zindex = 0;
}

bool Entity::HasCollision(Entity *ent) const
{
	sf::Rect<int> myRect(static_cast<int>(this->pos.x),
						 static_cast<int>(this->pos.y), 
						 static_cast<int>(this->pos.x + X_TILE_SIZE),
						 static_cast<int>(this->pos.y + Y_TILE_SIZE));

	sf::Rect<int> clRect(static_cast<int>(ent->pos.x),
						 static_cast<int>(ent->pos.y), 
						 static_cast<int>(ent->pos.x + X_TILE_SIZE),
						 static_cast<int>(ent->pos.y + Y_TILE_SIZE));

	return myRect.Intersects(clRect);
}

int Entity::SetZindex(int idx)
{
	return (this->zindex = idx);
}

bool Entity::operator<(Entity *ent)
{
	if(this->zindex > ent->zindex) return true;
	return false;
}

sf::Vector2<int> Entity::GetCenter()
{
	return sf::Vector2<int>(this->pos.x+(X_TILE_SIZE/2), this->pos.y+(Y_TILE_SIZE/2));
}

Entity::~Entity(void)
{
}

