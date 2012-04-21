#pragma once
#include "settings.h"
#include "Entity.h"

typedef void (*monsterAction)();


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

	void (*currentAction)();
	monsterAction actions[4];

};

void UpAndDown();
void LeftAndRight();
void Hunt();
void GoToWall();