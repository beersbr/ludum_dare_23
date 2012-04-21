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

int Warden::LoadSound(std::string filename, std::string id)
{
	return 1;
}

int Warden::AddEntity(std::string id, Entity* toAdd)
{
	this->entities.push_back(toAdd);
	sort(this->entities.begin(), this->entities.end());
	return 1;
}

sf::Image *Warden::GetImage(std::string id)
{
	return &(this->images[id]);
}

int Warden::DrawAll(sf::RenderTarget *rt)
{
	std::vector<Entity *>::iterator itr = this->entities.begin();
	for(itr; itr != this->entities.end(); itr++)
	{
		(*itr)->Draw(rt);
	}
}

int Warden::UpdateAll()
{

}