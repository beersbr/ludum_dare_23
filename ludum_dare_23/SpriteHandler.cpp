#include "SpriteHandler.h"


SpriteHandler::SpriteHandler(void)
{
}

SpriteHandler::~SpriteHandler(void)
{
}

SpriteHandler::SpriteHandler(SpriteHandler &sprite_handler)
{
	this->sprite = sf::Sprite(sprite_handler.sprite);

}

SpriteHandler::SpriteHandler(sf::Image *img, int _frame_lag = 5)
{
	if(img)
	{
		this->frames = img->GetWidth() % X_TILE_SIZE;
		this->frame_lag = _frame_lag;
		this->current_frame = 0;
		this->frame_lag_count = 0;
		sprite.SetImage(*img);
	}
}

int SpriteHandler::SetImage(sf::Image *img, int _frame_lag = 5)
{
	if(!img) return 0;
	this->frame_lag = _frame_lag;
	this->frame_lag_count = 0;
	this->frames = img->GetWidth() % X_TILE_SIZE;
	this->current_frame = 0;
	
	this->sprite.SetImage(*img);
	return 1;
}

int SpriteHandler::Draw(sf::RenderTarget *rt)
{
	if(frame_lag_count++ % frame_lag == 0)
	{
		current_frame = (current_frame + 1) % frames;
		this->_UpdateRectangle();
	}
	this->sprite.SetSubRect(rect);
}


int SpriteHandler::SetPostition(int x, int y)
{
	if( x < 0 || x > REZ_X || y < 0 || y > REZ_Y) return 0;

	this->sprite.SetX(x);
	this->sprite.SetY(y);

	return 1;
}

int SpriteHandler::_UpdateRectangle()
{
	this->rect.Left = current_frame*X_TILE_SIZE;
	this->rect.Top = 0;
	this->rect.Right = current_frame * X_TILE_SIZE + X_TILE_SIZE;
	this->rect.Bottom = Y_TILE_SIZE;
}