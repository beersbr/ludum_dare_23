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

	sf::Sprite sp; 
	sp.SetImage(*this->img);
	sp.SetX(static_cast<float>(this->pos.x));
	sp.SetY(static_cast<float>(this->pos.y));
	rt->Draw(sp);

	return 0;
}

int Player::Update(void )
{
	return 0;
}