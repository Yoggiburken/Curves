#include"../include/Game.hpp"

sf::RenderWindow 	app(sf::VideoMode(800, 600, 32), "Test");

int main()
{
	app.setVerticalSyncEnabled(true);
	Game 	game;
	while(app.isOpen())
	{
		Game::Menu_RS state = game.menu();
		if(state == Game::Exit) {
			app.close();
		} else if(state == Game::Play) {
			game.run();
		}
	}
	return 0;
}
