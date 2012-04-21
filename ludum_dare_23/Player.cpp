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
	
	//rt->Draw();

	return 0;
}

int Player::Update(void )
{
	return 0;
}