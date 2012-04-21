#pragma once
#include "settings.h"
#include "Entity.h"

//typedef void (Monster::*monsterAction)();


class Monster :
	public Entity
{
public:
	Monster(void);
	Monster(double x, double y);
	~Monster(void);

	void Init();
	int Draw(sf::RenderTarget * rt) const;
	int Update(void );

	void UpAndDown();
	void LeftAndRight();
	void Hunt();
	void GoToWall();

	void resetStages();

	void (Monster::*currentAction)();
	void(Monster::*actions[4])();
private:
	double endX;
	double endY;
	bool   stages[10];
};
