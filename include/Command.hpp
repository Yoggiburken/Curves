#include<SFML/Graphics.hpp>

#ifndef COMMAND_HPP
#define COMMAND_HPP

enum InputType {
	KeyboardInput = 0,
	MouseInput
};

struct Command {
	InputType 					myInputType;
	sf::Event::EventType  		myEventType;
	sf::Keyboard::Key			myKeyCode;
	sf::Mouse::Button 			myButton;

	void operator=(const Command& other);
	void operator=(const InputType& other);
	void operator=(const sf::Event::EventType& other);
	void operator=(const sf::Keyboard::Key& other);
	void operator=(const sf::Mouse::Button& other);
};

#endif
