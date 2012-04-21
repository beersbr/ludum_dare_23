#pragma once

#include "settings.h"
#include "vector.h"

#define ROOM_BORDER_CODE 2
#define ROOM_GROUND_CODE 1

class Room
{
public:
	Room(void);
	Room(Vector2D position);
	Room(Vector2D position, Vector2D size);
	Room(Vector2D position, int size);
	Room(const Room& rm);
	~Room(void);
	char borderCode;
	char groundCode;
	Vector2D position;
	Vector2D dimensions;
};

