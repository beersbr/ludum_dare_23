#include "Monster.h"


Monster::Monster(void)
{
	this->friction = 0.88;
	this->sprite = new SpriteHandler();
	this->type = MONSTER;
}

Monster::Monster(double x, double y): Entity(x, y)
{
	Init();
}

void Monster::Init()
{
	this->type = MONSTER;
	this->friction = 0.88;
	this->sprite = new SpriteHandler();

	//Set the actions;
	actions[0] = &UpAndDown;
	actions[1] = &LeftAndRight;
	actions[2] = &Hunt;
	actions[3] = &GoToWall;

	resetStages();
	this->stopMoving = false;
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
	Entity::Update();
	return 0;
}

int Monster::Update(InputHandler *input, std::vector<Entity *> entities)
{
	Entity::Update();

	//Keep calling the current actions, they'll pass eachother off.
	currentAction(this);
	if(!stopMoving)
		return 0;

	this->pos.x += (this->ax *= this->friction);
	this->pos.y += (this->ay *= this->friction);
	this->curRotation += 0.2f;
	this->sprite->SetPostition(static_cast<int>(this->pos.x), static_cast<int>(this->pos.y), this->curRotation);
	return 1;
}

//Need to figure out when stages reset
void UpAndDown(Monster* mon)
{
	static int updateCount = 0;
	//Lets move up a little, then down some.
	int randNum = 0;

	if(mon->stages[0]) 
	{
		//first stage. move up
		//we'll stop by chance
		randNum = rand() % 100 + 1;
		if(randNum >= 50)
		{
			//moves to the next stage
			//pause first though
			mon->stopMoving = true;
			if(updateCount > 400)
			{
				randNum = rand() % 100 + 1;
				if(randNum > 90)
				{
					mon->stopMoving = false;
					mon->stages[0] = false;
					mon->stages[1] = true;
					updateCount = 0;
				}
			}
		}
		else if ( mon->pos.y <= 0)
		{
			// hit a wall, need to go down.
			//pause first though
			mon->stopMoving = true;
			if(updateCount > 400)
			{
				randNum = rand() % 100 + 1;
				if(randNum > 95)
				{
					mon->stopMoving = false;
					mon->stages[0] = false;
					mon->stages[1] = true;
					updateCount = 0;
				}
			}
		}
		else
		{
			mon->ay -= 0.2;
		}
	}
	if(mon->stages[1])
	{
		randNum = rand() % 200 +1;
		if(randNum >= 120)
		{
			//move to a different action
			//pause first though
			mon->stopMoving = true;
			if(updateCount > 400)
			{
				randNum = rand() % 100 + 1;
				if(randNum > 90)
				{
					mon->stopMoving = false;
					mon->resetStages();
					mon->currentAction = mon->actions[rand() % 2];
					updateCount = 0;
				}
			}
		}
		else if ((mon->pos.y + Y_TILE_SIZE) >= REZ_Y)
		{
			// hit a wall, need to go down.
			//pause first though
			mon->stopMoving = true;
			if(updateCount > 400)
			{
				randNum = rand() % 100 + 1;
				if(randNum > 95)
				{
					mon->stopMoving = false;
					mon->stages[0] = false;
					mon->stages[1] = true;
					updateCount = 0;
				}
			}
		}
		else
		{
			mon->ay += 0.2;
		}
	}
	updateCount++;

}

void LeftAndRight(Monster* mon)
{
	static int updateCount = 0;
	//Lets move up a little, then down some.
	int randNum = 0;

	if(mon->stages[0]) 
	{
		//first stage. move up
		//we'll stop by chance
		randNum = rand() % 100 + 1;
		if(randNum >= 50)
		{
			//moves to the next stage
			//pause first though
			mon->stopMoving = true;
			if(updateCount > 400)
			{
				randNum = rand() % 100 + 1;
				if(randNum > 90)
				{
					mon->stopMoving = false;
					mon->stages[0] = false;
					mon->stages[1] = true;
					updateCount = 0;
				}
			}
		}
		else if ( mon->pos.x <= 0)
		{
			// hit a wall, need to go down.
			//pause first though
			mon->stopMoving = true;
			if(updateCount > 400)
			{
				randNum = rand() % 100 + 1;
				if(randNum > 95)
				{
					mon->stopMoving = false;
					mon->stages[0] = false;
					mon->stages[1] = true;
					updateCount = 0;
				}
			}
		}
		else
		{
			mon->ax -= 0.2;
		}
	}
	if(mon->stages[1])
	{
		randNum = rand() % 200 +1;
		if(randNum >= 120)
		{
			//move to a different action
			//pause first though
			mon->stopMoving = true;
			if(updateCount > 400)
			{
				randNum = rand() % 100 + 1;
				if(randNum > 90)
				{
					mon->stopMoving = false;
					mon->resetStages();
					mon->currentAction = mon->actions[rand() % 2];
					updateCount = 0;
				}
			}
		}
		else if ((mon->pos.x + X_TILE_SIZE) >= REZ_X)
		{
			// hit a wall, need to go down.
			//pause first though
			mon->stopMoving = true;
			if(updateCount > 400)
			{
				randNum = rand() % 100 + 1;
				if(randNum > 95)
				{
					mon->stopMoving = false;
					mon->stages[0] = false;
					mon->stages[1] = true;
					updateCount = 0;
				}
			}
		}
		else
		{
			mon->ax += 0.2;
		}
	}
	updateCount++;
}

void Hunt(Monster* mon)
{

}

void GoToWall(Monster* mon)
{

}

void Chase(Monster* mon)
{

}

void Avoid(Monster* mon)
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
