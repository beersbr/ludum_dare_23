#include "Vector.h"


Vector2D::Vector2D(void)
{
	this->x = 0;
	this->y = 0;
}

Vector2D::Vector2D(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2D::Vector2D(Vector2D &v)
{
	this->x = v.x;
	this->y = v.y;
}

Vector2D::~Vector2D(void)
{
}
