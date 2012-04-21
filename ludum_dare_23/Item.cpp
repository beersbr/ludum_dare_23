#include "Item.h"


Item::Item(void)
{
}

Item::Item(double x, double y)
{
	this->pos.x = x;
	this->pos.y = y;

}

Item::~Item(void)
{
}



int Item::Update()
{
	return 1;
}


int Item::Draw(sf::RenderTarget *rt) const
{
	return 1;
}
