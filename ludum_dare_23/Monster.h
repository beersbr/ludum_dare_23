#pragma once
#include "settings.h"
#include "Entity.h"
#include "InputHandler.h"

//typedef void (*monsterAction)(Monster);


class Monster :
	public Entity
{
public:
	Monster(void);
	Monster(double x, double y);
	~Monster(void);

	void Init();
	int Draw(sf::RenderTarget * rt) const;
	int Update();
	int Update(InputHandler *input, void *warden);
	int SetImage(sf::Image *);

	void resetStages();

	void (*currentAction)(Monster*);
	void(*actions[4])(Monster*);

	double endX;
	double endY;
	bool   stages[10];
	bool   stopMoving;
};

void UpAndDown(Monster* mon);
void LeftAndRight(Monster* mon);
void Hunt(Monster* mon);
void GoToWall(Monster* mon);
void Chase(Monster* mon);
void Avoid(Monster* mon);