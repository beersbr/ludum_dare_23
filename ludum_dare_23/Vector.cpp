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

Vector2D::Vector2D(const Vector2D& vec)
{
	this->x = vec.x;
	this->y = vec.y;
}

Vector2D::~Vector2D(void)
{
}
