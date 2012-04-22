#include "settings.h"
#include "Warden.h"
#include "InputHandler.h"
#include "Player.h"
#include "Monster.h"
#include "GameMap.h"

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
	
	//Seed that random generator
	srand(time(NULL));
	// What does ^ do?

	InputHandler *input = InputHandler::instance();
	Warden *warden = Warden::instance();
	GameMap* gameMap = new GameMap();
	sf::Event game_event;
	GAME_STATE GameState = RUNNING;

	warden->LoadImage("media_assets\\Grass.png", "grass");
	warden->LoadImage("media_assets\\Dirt.png", "dirt");
	warden->LoadImage("media_assets\\Rock.png", "rock");
	warden->LoadImage("media_assets\\gman.png", "mon");
	warden->LoadImage("media_assets\\TestSprite.png", "test");

	// Somehow this seems like it needs refactoring but I'm not sure how to go about it.
	gameMap->GenerateStaticMap();
	gameMap->GetMapImage(warden);

	// END GAME SETUP


	// START SHOULD BE PER LEVEL

	Player *p = new Player(500, 500);
	p->SetZindex(1);
	Monster *m = new Monster(100, 100);

	p->SetImage(warden->GetImage("grass"));
	m->SetImage(warden->GetImage("grass"));

	warden->AddEntity(p);
	warden->AddEntity(m);
	
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

		warden->UpdateAll(input);
		warden->DrawMap(&App);
		warden->DrawAll(&App);

		App.Display();
	}

	return EXIT_SUCCESS;
}