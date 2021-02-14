#include <iostream>
#include <time.h>

#include "Game.hpp"
#include "WelcomeScreen.hpp"
#include "ScoreLoader.hpp"

int main()
{
	/* Create a welcomescreen and display it until you exit */
	WelcomeScreen ws;
	ws.display();

	/* Run the game */
	Game game;
	game.run();

	// exit with code 0
	return 0;
}