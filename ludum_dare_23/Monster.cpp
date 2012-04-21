#include "Monster.h"


Monster::Monster(void)
{
	this->friction = 0.88;
	this->sprite = new SpriteHandler();
}

Monster::Monster(double x, double y): Entity(x, y)
{
	Init();
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

	resetStages();

	this->currentAction = this->actions[0];
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
	this->pos.x += (this->ax *= this->friction);
	this->pos.y += (this->ay *= this->friction);

	this->sprite->SetPostition(static_cast<int>(this->pos.x), static_cast<int>(this->pos.y));
	return 0;
}

//Need to figure out when stages reset
void UpAndDown(Monster* mon)
{
	//Lets move up a little, then down some.
	int randNum = 0;

	if(mon->stages[0]) 
	{
		//first stage. move up
		//we'll stop by chance
		randNum = rand() % 10 + 1;
		if(randNum >= 8 || mon->pos.y <= 0)
		{
			//moves to the next stage
			mon->stages[0] = false;
			mon->stages[1] = true;
		}
		else
		{
			mon->ay -= 0.5;
		}
	}
	if(mon->stages[1])
	{
		randNum = rand() % 10 +1;
		if(randNum <= 8 || mon->pos.y >= REZ_Y)
		{
			//move to a different action
			mon->resetStages();
			//mon->currentAction = mon->actions[rand() % 4];
		}
		else
		{
			mon->ay += 0.8;
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