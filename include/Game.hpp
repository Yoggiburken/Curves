#include<vector>
#include"Command.hpp"
#include"Worm.hpp"

#ifndef GAME_HPP
#define GAME_HPP
class Game {
private:
	std::vector<Command>			commands;
	std::vector<Worm>				players;

	void							initCommands(int number_of_players);
public:
	void							run(int number_of_players);
	int								menu();
};
#endif
