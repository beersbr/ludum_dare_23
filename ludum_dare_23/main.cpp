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

#if DEBUG
#include <d
#endif

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


	gameMap->GenerateStaticMap();
	gameMap->GetMapImage(warden);
	//mapSprite.SetImage(gameMap->GetMapImage(warden));



	warden->LoadImage("media_assets\\Grass.png", "grass");
	warden->LoadImage("media_assets\\Dirt.png", "dirt");
	warden->LoadImage("media_assets\\Rock.png", "rock");
	warden->LoadImage("media_assets\\TestSprite.png", "test");

	// END GAME SETUP


	// START SHOULD BE PER LEVEL

	Player *p = new Player(500, 500);
	p->SetZindex(-1);
	Monster *m = new Monster(100, 100);

	p->SetImage(warden->GetImage("test"));
	m->SetImage(warden->GetImage("dirt"));

	warden->AddEntity(p);
	warden->AddEntity(m);
	warden->DrawMap(&App);
	
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

		if(input->KeyIsDown(sf::Key::W))
		{
			p->ay -= 0.8;
		}
		if(input->KeyIsDown(sf::Key::S))
		{
			p->ay += 0.8;
		}
		if(input->KeyIsDown(sf::Key::A))
		{
			p->ax -= 0.8;
		}
		if(input->KeyIsDown(sf::Key::D))
		{
			p->ax += 0.8;
		}

		warden->UpdateAll();
		warden->DrawAll(&App);

		App.Display();
		App.Clear();
	}

	return EXIT_SUCCESS;
}