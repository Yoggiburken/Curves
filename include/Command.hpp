#include<SFML/Graphics.hpp>

#ifndef COMMAND_HPP
#define COMMAND_HPP

enum InputType {
	KeyboardInput,
	MouseInput
};

struct Command {
	InputType 					myInputType;
	sf::Keyboard::Key			myKeyCode;
	sf::Mouse::Button			myButton;
	bool						bindNextKeypress;

	void operator=(const Command& other);
	void operator=(const InputType& other);
	void operator=(const sf::Keyboard::Key& other);
	void operator=(const sf::Mouse::Button& other);
};

#endif
