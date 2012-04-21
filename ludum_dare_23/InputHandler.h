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
	
private: 
	InputHandler();

	static InputHandler *_instance;
	std::map<sf::Key::Code, int> keys;
};