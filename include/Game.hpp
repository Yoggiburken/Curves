#include<vector>
#include"Command.hpp"
#include"Worm.hpp"

#ifndef GAME_HPP
#define GAME_HPP
class Game {
private:
	std::vector<Command>			commands;

	void							initCommands();
public:
	void							run();
};
#endif
