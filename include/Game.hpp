#include<map>
#include"Command.hpp"
#include"Worm.hpp"

#ifndef GAME_HPP
#define GAME_HPP
class Game {
private:
	std::map<std::string, Command>	commands;

	void							initCommands();
public:
	void							run();
};
#endif
