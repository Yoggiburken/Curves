#include"../include/Game.hpp"

sf::RenderWindow 	app(sf::VideoMode(800, 600, 32), "Test");

int main()
{
	Game 	game;
	while(app.isOpen())
	{
		int players = game.menu();
		if(players == 0) {
			app.close();
		} else if(players > 0) {
			game.run(players);
		}
	}
	return 0;
}
