#include "Player.h"


Player::Player(void)
{
}

Player::Player(double x, double y):Entity(x, y)
{
}

Player::~Player(void)
{
}

int Player::Draw(sf::RenderTarget *rt) const
{
	//Just for testing the drawing stuff

	sf::Shape rect;
	rect.AddPoint(this->pos.x - (X_TILE_SIZE/2), this->pos.y - (Y_TILE_SIZE/2), sf::Color(0, 0, 255));
	rect.AddPoint(this->pos.x + (X_TILE_SIZE/2), this->pos.y - (Y_TILE_SIZE/2), sf::Color(0, 0, 255));
	rect.AddPoint(this->pos.x + (X_TILE_SIZE/2), this->pos.y + (Y_TILE_SIZE/2), sf::Color(0, 0, 255));
	rect.AddPoint(this->pos.x - (X_TILE_SIZE/2), this->pos.y + (Y_TILE_SIZE/2), sf::Color(0, 0, 255));
	rt->Draw(rect);

	return 0;
}

int Player::Update(void )
{
	return 0;
}