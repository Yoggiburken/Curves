#include<vector>
#include"Command.hpp"
#include"Worm.hpp"

#ifndef GAME_HPP
#define GAME_HPP
class Game {
private:
	std::vector<Command>			commands;
	std::vector<Worm>				players;

	void							initCommands();
public:
	void							run(int players);
	int								menu();
};
#endif
