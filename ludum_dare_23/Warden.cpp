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

// TODO create a collision hash map of the screen so that getting appropriate collidable items is not so 
// painful to the CPU

int Warden::UpdateAll(InputHandler *input)
{
	std::vector<Entity *>::iterator itr = this->entities.begin();
	sf::Rect<int> bounding_rect;

	for(itr; itr != this->entities.end(); itr++)
	{
		// TODO Get the bounding rectangle for the current item. In this case the bounding rectangle would just get items that are
		// close enough to be checked and acted upon when there is a collision.

		bounding_rect.Top = (*itr)->pos.y - Y_TILE_SIZE;
		bounding_rect.Left = (*itr)->pos.x - X_TILE_SIZE;
		bounding_rect.Right = (*itr)->pos.x + Y_TILE_SIZE * 2;
		bounding_rect.Bottom = (*itr)->pos.x + X_TILE_SIZE * 2;

		for(std::vector<Entity *>::iterator i = this->entities.begin(); i != this->entities.end(); i++)
		{

		}

		switch((*itr)->type)
		{
		case PLAYER:
			(dynamic_cast<Player*>(*itr))->Update(input, NULL);
			break;
		case MONSTER:
			(dynamic_cast<Monster*>(*itr))->Update(input, NULL);
			break;
		}
	}
	CheckCollisionAll();

	return 1;
}


// This function is now deprecated and will be moved after a few more commits. It will stay until we are certain
// that it is not needed.
int Warden::CheckCollisionAll()
{
	std::vector<Entity *>::iterator itr = this->entities.begin(), temp_itr;

	sf::Rect<int> bounding_rect;

	for(itr; itr != this->entities.end(); itr++)
	{
		if((*itr)->type != MONSTER && (*itr)->type != PLAYER) continue;

		// bounding rectangle for checking which objects are close enough to be worth checking
		// collision against
		bounding_rect.Top = (*itr)->pos.y - Y_TILE_SIZE;
		bounding_rect.Left = (*itr)->pos.x - X_TILE_SIZE;
		bounding_rect.Right = (*itr)->pos.x + Y_TILE_SIZE * 2;
		bounding_rect.Bottom = (*itr)->pos.x + X_TILE_SIZE * 2;

		for(temp_itr = this->entities.begin(); temp_itr != this->entities.end(); temp_itr++)
		{
			// Don't check agains the same object
			if(itr == temp_itr) continue; 

			if(bounding_rect.Contains((*temp_itr)->GetCenter().x, (*temp_itr)->GetCenter().y))
			{
				if((*itr)->rect.Intersects((*temp_itr)->rect))
				{
					// act on collide here...
					(*itr)->sprite->SetImage(this->GetImage("rock"));
				}
				else
				{
					(*itr)->sprite->SetImage(this->GetImage("grass"));
				}
			}
		}
	}

	return 1;
}