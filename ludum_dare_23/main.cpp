#include "settings.h"
#include "Warden.h"
#include "InputHandler.h"
#include "Player.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <fstream>

int main()
{
	sf::RenderWindow App(sf::VideoMode(REZ_X, REZ_Y, 32), WINDOW_TITLE);
	App.SetFramerateLimit(FRAME_LIMIT);


	// START GAME SETUP

	InputHandler *input = InputHandler::instance();
	Warden *warden = Warden::instance();
	sf::Event game_event;
	GAME_STATE GameState = RUNNING;

	warden->LoadImage("media_assets/Grass.png", "grass");
	warden->LoadImage("media_assets/Dirt.png", "dirt");
	warden->LoadImage("media_assets/Rock.png", "rock");
	warden->LoadImage("media_assets/TestSprite.png", "test");

	// END GAME SETUP


	// START SHOULD BE PER LEVEL

	Player *p = new Player(500, 500);

	// END SHOULD BE PER LEVEL

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