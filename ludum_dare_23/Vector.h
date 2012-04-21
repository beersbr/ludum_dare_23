#pragma once
class Vector2D
{
public:
	Vector2D(void);
	Vector2D(int x, int y);
	Vector2D(const Vector2D& vec);
	~Vector2D(void);
	double x;
	double y;
};

