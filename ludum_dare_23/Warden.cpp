#include "Warden.h"

Warden* Warden::_instance = NULL;
std::map<std::string, sf::Image> Warden::images;
std::map<std::string, sf::Sound> Warden::sounds;

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
	this->entities[id] = toAdd;
	return 1;
}

sf::Image *Warden::GetImage(std::string id)
{
	return &images[id];
}