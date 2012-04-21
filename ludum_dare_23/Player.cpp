#include "Player.h"

Player::Player(void)
{
	this->sprite = new SpriteHandler();
}

Player::Player(double x, double y):Entity(x, y)
{
	this->sprite = new SpriteHandler();
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
	return 0;
}