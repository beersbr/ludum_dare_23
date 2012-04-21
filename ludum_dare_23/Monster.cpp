#include "Monster.h"


Monster::Monster(void)
{
	this->friction = 0.88;
	this->sprite = new SpriteHandler();
}

Monster::Monster(double x, double y): Entity(x, y)
{
	Init();
	this->currentAction = this->actions[0];
}

void Monster::Init()
{

	this->friction = 0.88;
	this->sprite = new SpriteHandler();

	//Set the actions;
	actions[0] = &UpAndDown;
	actions[1] = &LeftAndRight;
	actions[2] = &Hunt;
	actions[3] = &GoToWall;
}


Monster::~Monster(void)
{
}

int Monster::Draw(sf::RenderTarget * rt) const
{
	this->sprite->Draw(rt);
	return 0;
}

int Monster::SetImage(sf::Image *img)
{
	if(!this->sprite->SetImage(img)) return 0;
	return 1;
}

int Monster::Update()
{
	//Keep calling the current actions, they'll pass eachother off.
	currentAction(this);
	this->sprite->SetPostition(static_cast<int>(this->pos.x), static_cast<int>(this->pos.y));
	return 0;
}

//Need to figure out when stages reset
void UpAndDown(Monster* mon)
{
	//Lets move up a little, then down some.

	//Down poriton
	if(mon->stages[1])
	{
		double dY = rand() % (REZ_Y - 10) + 10;
		while(mon->pos.y + dY > REZ_Y)
		{
			dY = rand() % (REZ_Y - 10) + 10;
		}
		mon->endY = dY + mon->pos.y;
		mon->stages[1] = false;
	}
	else
	{
		mon->pos.y += mon->ay; //Move
		//Look for player here!

		if(mon->pos.y >= mon->endY)
		{
			mon->resetStages(); //reset stage, set action to something else!
			mon->currentAction = mon->actions[rand() % 4]; 
		}
	}

	//Up portion
	if(mon->stages[0])
	{
		//set an endpoint on the y axis
		double dY = rand() % (REZ_Y - 10) + 10;
		//Border checking
		while(mon->pos.y - dY < 0)
		{
			dY = rand() % (REZ_Y - 10) + 10;
		}

		mon->endY = dY - mon->pos.y;
		mon->stages[0] = false;
	}
	else
	{
		mon->pos.y -= mon->ay; //Move
		//Look for player here!

		if(mon->pos.y <= mon->endY)
		{
			//next stage, go down.
			mon->stages[1] = true;
		}
	}


}

void LeftAndRight(Monster* mon)
{

}

void Hunt(Monster* mon)
{

}

void GoToWall(Monster* mon)
{

}

void Monster::resetStages()
{
	for(int i = 0; i < 9; i++)
	{
		this->stages[i] = false;
	}
	stages[0] = true;
}