#include "Warden.h"

Warden* Warden::_instance = NULL;
std::map<std::string, sf::Image> Warden::images;
std::map<std::string, sf::Sound> Warden::sounds;
std::vector<Entity *> Warden::entities;

Warden *Warden::instance()
{
	if(Warden::_instance = NULL) Warden::_instance = new Warden();
	return Warden::_instance;
}

Warden::Warden(void)
{
}

Warden::~Warden(void)
{
}

int Warden::LoadImage(std::string filename, std::string id)
{
	if(this->images[id].LoadFromFile(filename)) return 1;
	return 0;
}

int Warden::LoadImage(std::string id, sf::Image img)
{
	this->images[id] = img;
	return 1;
}

int Warden::LoadSound(std::string filename, std::string id)
{
	return 1;
}

int Warden::AddEntity(Entity* ent)
{
	this->entities.push_back(ent);

	std::sort(this->entities.begin(),
		this->entities.end(), 
		[](const Entity *a, const Entity *b) -> bool
		{ 
			return (a->zindex < b->zindex); 
		});
	return 1;
}

sf::Image *Warden::GetImage(std::string id)
{
	return &(this->images[id]);
}

int Warden::DrawMap(sf::RenderTarget *rt)
{
	sf::Sprite mapSprite;

	mapSprite.SetImage(images["gameMap"]);
	mapSprite.SetPosition(0, 0);
	rt->Draw(mapSprite);
	return 1;
}

int Warden::DrawAll(sf::RenderTarget *rt)
{
	std::vector<Entity *>::iterator itr = this->entities.begin();
	for(itr; itr != this->entities.end(); itr++)
	{
		(*itr)->Draw(rt);
	}
	return 1;
}

int Warden::UpdateAll()
{
	std::vector<Entity *>::iterator itr = this->entities.begin();
	for(itr; itr != this->entities.end(); itr++)
	{
		(*itr)->Update();
	}
	return 1;
}

int Warden::CheckCollisionAll()
{
	std::vector<Entity *>::iterator itr = this->entities.begin(), temp_itr;

	sf::Rect<int> bounding_rect;

	for(itr; itr != this->entities.end(); itr++)
	{
		if((*itr)->type != MONSTER || (*itr)->type != PLAYER) continue;

		// bounding rectangle
		bounding_rect.Top = (*itr)->pos.y - Y_TILE_SIZE * 2;
		bounding_rect.Left = (*itr)->pos.x - X_TILE_SIZE * 2;
		bounding_rect.Bottom = (*itr)->pos.x + X_TILE_SIZE * 2;
		bounding_rect.Right = (*itr)->pos.x + Y_TILE_SIZE * 2;

		for(temp_itr = this->entities.begin(); temp_itr != this->entities.end(); temp_itr++)
		{
			if(bounding_rect.Contains((*temp_itr)->GetCenter().x, (*temp_itr)->GetCenter().y))
			{
				// check for collision here... again...
				//if(bounding_rect.Intersects(
			}
		}
	}
}