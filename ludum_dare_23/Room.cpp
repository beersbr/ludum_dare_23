#include "Room.h"


Room::Room(void)
{
	this->borderCode = ROOM_BORDER_CODE;
	this->groundCode = ROOM_GROUND_CODE;
}

Room::Room(Vector2D position)
{
	this->borderCode = ROOM_BORDER_CODE;
	this->groundCode = ROOM_GROUND_CODE;
	this->position = position;
}

Room::Room(Vector2D position, Vector2D size)
{
	this->borderCode = ROOM_BORDER_CODE;
	this->groundCode = ROOM_GROUND_CODE;
	this->position = position;
	this->dimensions = size;
}

Room::Room(Vector2D position, int size)
{
	this->borderCode = ROOM_BORDER_CODE;
	this->groundCode = ROOM_GROUND_CODE;
	this->position = position;
	this->dimensions.x = (double)size;
	this->dimensions.y = (double)size;
}

Room::Room(const Room& rm)
{
	this->borderCode = rm.borderCode;
	this->groundCode = rm.groundCode;
	this->position = rm.position;
	this->dimensions = rm.dimensions;
}

Room::~Room(void)
{
}
