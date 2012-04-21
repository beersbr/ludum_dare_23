#include "Monster.h"


Monster::Monster(void)
{
}

Monster::Monster(double x, double y)
{
	this->pos.x = x;
	this->pos.y = y;
}

void Monster::Init()
{
	//Set the actions;
	actions[0] = UpAndDown;
	actions[1] = LeftAndRight;
	actions[2] = Hunt;
	actions[3] = GoToWall;
}


Monster::~Monster(void)
{
}

int Monster::Draw(sf::RenderTarget * rt) const
{
	sf::Sprite sp; 
	//sp.SetImage(*this->img);
	sp.SetX(static_cast<float>(this->pos.x));
	sp.SetY(static_cast<float>(this->pos.y));
	sp.Rotate(static_cast<float>(this->curRotation));
	rt->Draw(sp);

	return 0;
}

int Monster::Update()
{
	//Keep calling the current actions, they'll pass eachother off.
	this->currentAction();
	return 1;
}

void UpAndDown()
{
	//Lets move up a little, then down some.

}

void LeftAndRight()
{

}

void Hunt()
{

}

void GoToWall()
{

}