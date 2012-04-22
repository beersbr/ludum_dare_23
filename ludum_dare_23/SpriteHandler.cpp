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

SpriteHandler::SpriteHandler(sf::Image *img, int _frame_lag)
{
	if(img)
	{
		this->frames = img->GetWidth() % X_TILE_SIZE;
		if(!this->frames)
			frames++;
		this->frame_lag = _frame_lag;
		this->current_frame = 0;
		this->frame_lag_count = 0;
		this->rect.Top = 0;
		this->rect.Left = 0;
		this->rect.Right = X_TILE_SIZE;
		this->rect.Bottom = Y_TILE_SIZE;

		sprite.SetImage(*img);
	}
}

int SpriteHandler::SetImage(sf::Image *img, int _frame_lag)
{
	if(!img) return 0;
	this->frame_lag = _frame_lag;
	this->frame_lag_count = 0;
	this->frames = img->GetWidth() / X_TILE_SIZE;
	if(!this->frames)
		frames++;
	this->current_frame = 0;
	this->rect.Top = 0;
	this->rect.Left = 0;
	this->rect.Right = X_TILE_SIZE;
	this->rect.Bottom = Y_TILE_SIZE;
	
	this->sprite.SetImage(*img);
	return 1;
}

int SpriteHandler::Draw(sf::RenderTarget *rt)
{
	if(frame_lag_count++ == frame_lag)
	{
		current_frame = (current_frame + 1) % frames;
		frame_lag_count = 0;
		this->_UpdateRectangle();
	}

	this->sprite.SetSubRect(rect);
	rt->Draw(this->sprite);
	return 1;
}


int SpriteHandler::SetPostition(int x, int y, float rotation)
{
	this->sprite.SetX(x);
	this->sprite.SetY(y);
	this->sprite.SetRotation(rotation);

	return 1;
}

int SpriteHandler::_UpdateRectangle()
{
	this->rect.Left = current_frame*X_TILE_SIZE;
	this->rect.Top = 0;
	this->rect.Right = current_frame * X_TILE_SIZE + X_TILE_SIZE;
	this->rect.Bottom = Y_TILE_SIZE;
	return 1;
}