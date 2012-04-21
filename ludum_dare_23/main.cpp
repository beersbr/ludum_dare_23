#include "settings.h"
#include "InputHandler.h"
#include "Player.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

int main()
{
	sf::RenderWindow App(sf::VideoMode(REZ_X, REZ_Y, 32), WINDOW_TITLE);
	App.SetFramerateLimit(FRAME_LIMIT);

	sf::Event game_event;

	InputHandler *input = InputHandler::instance();
	GAME_STATE GameState = RUNNING;

	Player *p = new Player();

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

		p->Draw(&App);

		App.Display();
	}

	return EXIT_SUCCESS;
}