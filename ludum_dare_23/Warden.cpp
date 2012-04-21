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
	std::vector<Entity *>::iterator itr = this->entities.begin();
	std::vector<Entity *> temp;

	for(itr; itr != this->entities.end(); itr++)
	{

	}
}