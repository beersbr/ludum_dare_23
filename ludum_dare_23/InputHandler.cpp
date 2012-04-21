#include "InputHandler.h"

InputHandler *InputHandler::_instance = NULL;

InputHandler *InputHandler::instance()
{
	if(!InputHandler::_instance) InputHandler::_instance = new InputHandler();
	return InputHandler::_instance;
}

InputHandler::InputHandler(){
}

int InputHandler::UpdateEvents(sf::Event e){
	if(e.Type == sf::Event::KeyPressed){
		this->keys[e.Key.Code] = 1;
	}
	else if(e.Type == sf::Event::KeyReleased){
		this->keys[e.Key.Code] = 0;
	}
	return 0;
}

int InputHandler::KeyIsDown(sf::Key::Code k){
	return keys[k];
}