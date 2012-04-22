#include "Player.h"

Player::Player(void)
{
	this->friction = 0.88;
	this->sprite = new SpriteHandler();
	this->type = PLAYER;
}

Player::Player(double x, double y):Entity(x, y)
{
	this->friction = 0.88;
	this->sprite = new SpriteHandler();
	this->type = PLAYER;
}

Player::~Player(void)
{
}

int Player::Draw(sf::RenderTarget *rt) const
{
	this->sprite->Draw(rt);
	return 1;
}

int Player::SetImage(sf::Image *img)
{
	if(!this->sprite->SetImage(img)) return 0;
	return 1;
}

int Player::Update(void )
{
	Entity::Update();

	this->pos.x += (this->ax *= this->friction);
	this->pos.y += (this->ay *= this->friction);

	this->sprite->SetPostition(static_cast<int>(this->pos.x), static_cast<int>(this->pos.y));
	return 0;
}