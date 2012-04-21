#include "Block.h"


Block::Block(void)
{

}

Block::Block(Vector2D position)
{
	this->position = position;
	this->dimensions.x = 0.0;
	this->dimensions.y = 0.0;
}

Block::Block(Vector2D position, Vector2D dims)
{
	this->position = position;
	this->dimensions = dims;
}

Block::Block(const Block& b)
{
	this->position = b.position;
	this->dimensions = b.dimensions;
}

double Block::blockWidth()
{
	return this->dimensions.x;
}

double Block::blockHeight()
{
	return this->dimensions.y;
}

Block::~Block(void)
{
}
