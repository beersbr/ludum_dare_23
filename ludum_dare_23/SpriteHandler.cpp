#include "SpriteHandler.h"


SpriteHandler::SpriteHandler(void)
{
}

SpriteHandler::~SpriteHandler(void)
{
}

SpriteHandler::SpriteHandler(sf::Image *img)
{
	if(img)
	{
		sprite.SetImage(*img);
		//frames = 
	}
}

int SpriteHandler::GetImage(sf::Image *img)
{
	if(!img) return 0;
	sprite.SetImage(*img);
	return 1;
}

int SpriteHandler::Draw(sf::RenderTarget *rt)
{

}
