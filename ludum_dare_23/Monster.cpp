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
	actions[0] = &Monster::UpAndDown;
	actions[1] = &Monster::LeftAndRight;
	actions[2] = &Monster::Hunt;
	actions[3] = &Monster::GoToWall;
}


Monster::~Monster(void)
{
}

int Monster::Draw(sf::RenderTarget * rt) const
{
	sf::Sprite sp; 
	sp.SetImage(*this->img);
	sp.SetX(static_cast<float>(this->pos.x));
	sp.SetY(static_cast<float>(this->pos.y));
	sp.Rotate(static_cast<float>(this->curRotation));
	rt->Draw(sp);

	return 0;
}

int Monster::Update()
{
	//Keep calling the current actions, they'll pass eachother off.
	this->*currentAction();

}

//Need to figure out when stages reset
void Monster::UpAndDown()
{
	//Lets move up a little, then down some.

	//Down poriton
	if(stages[1])
	{
		double dY = rand() % (REZ_Y - 10) + 10;
		while(this->pos.y + dY > REZ_Y)
		{
			dY = rand() % (REZ_Y - 10) + 10;
		}
		endY = dY + this->pos.y;
		stages[1] = false;
	}
	else
	{
		this->pos.y += ay; //Move
		//Look for player here!

		if(this->pos.y >= endY)
		{
			resetStages(); //reset stage, set action to something else!
			this->currentAction = actions[rand() % 4]; 
		}
	}

	//Up portion
	if(stages[0])
	{
		//set an endpoint on the y axis
		double dY = rand() % (REZ_Y - 10) + 10;
		//Border checking
		while(this->pos.y - dY < 0)
		{
			dY = rand() % (REZ_Y - 10) + 10;
		}

		endY = dY - this->pos.y;
		stages[0] = false;
	}
	else
	{
		this->pos.y -= ay; //Move
		//Look for player here!

		if(this->pos.y <= endY)
		{
			//next stage, go down.
			stages[1] = true;
		}
	}


}

void Monster::LeftAndRight()
{

}

void Monster::Hunt()
{

}

void Monster::GoToWall()
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