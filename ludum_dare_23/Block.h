#pragma once

#include "settings.h"
#include "Vector.h"

class Block
{
public:
	Block(void);
	Block(Vector2D position);
	Block(Vector2D position, Vector2D dims);
	Block(const Block& b);
	~Block(void);
	Vector2D position;
	Vector2D dimensions;
	double blockWidth();
	double blockHeight();
	double blockX();
	double blockY();
};

