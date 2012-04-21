#include "settings.h"
#include "InputHandler.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

int main()
{
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "test");
	App.SetFramerateLimit(60);

	sf::Event game_event;

	InputHandler *input = InputHandler::instance();
	GAME_STATE GameState = RUNNING;

	while(GameState)
	{
		while(App.GetEvent(game_event))
		{
			input->UpdateEvents(game_event);
		}

		if(input->KeyIsDown(sf::Key::Escape))
		{
			GameState = STOPPED;
		}

		App.Display();
	}

	return EXIT_SUCCESS;
}