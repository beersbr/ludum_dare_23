#include "InputHandler.h"

InputHandler *InputHandler::_instance = NULL;

InputHandler *InputHandler::instance()
{
	if(!InputHandler::_instance) InputHandler::_instance = new InputHandler();
	return InputHandler::_instance;
}

InputHandler::InputHandler(){
}

int InputHandler::ClearEvents()
{
	events.clear();
	return 1;
}

std::vector<sf::Event> InputHandler::GetEvents(sf::Event::EventType t)
{
	std::vector<sf::Event> return_list;
	std::vector<sf::Event>::iterator itr;
	for(itr = events.begin(); itr != events.end(); itr++)
	{
		if((*itr).Type == t) return_list.push_back((*itr));
	}
	return return_list;
}

int InputHandler::UpdateEvents(sf::Event e){
	events.push_back(e);

	if(e.Type == sf::Event::KeyPressed){
		this->keys[e.Key.Code] = 1;
	}
	else if(e.Type == sf::Event::KeyReleased){
		this->keys[e.Key.Code] = 0;
	}

	return 1;
}

int InputHandler::KeyIsDown(sf::Key::Code k){
	return keys[k];
}