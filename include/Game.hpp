#include<vector>
#include"Command.hpp"
#include"Worm.hpp"
#include"Button.hpp"
#include"MediaBucket.hpp"

#ifndef GAME_HPP
#define GAME_HPP
class Game {
private:
	std::vector<Command>			commands;
	std::vector<Worm>				players;
	
	std::vector<Button>				menu_buttons;
	int 							number_of_players;

	MediaBucket						mediabucket;

	void							initCommands();
	void							initMenuButtons();
public:
									Game();
	enum Menu_RS {Play, Menu, Exit};

	void							run();
	Menu_RS							menu();
};
#endif
