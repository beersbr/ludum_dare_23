#pragma once

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <map>

class InputHandler
{
public:
	static InputHandler *instance();
	
	int UpdateEvents(sf::Event e);
	int KeyIsDown(sf::Key::Code code);
	int ClearEvents();
	std::vector<sf::Event> GetEvents(sf::Event::EventType t);

private: 
	InputHandler();

	static InputHandler *_instance;
	std::map<sf::Key::Code, int> keys;
	std::vector<sf::Event> events;
};