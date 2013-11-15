#include"../include/Command.hpp"


void Command::operator=(const Command& other)
{
	this->myInputType 	= other.myInputType;
	this->myKeyCode		= other.myKeyCode;
	this->myButton		= other.myButton;
}

void Command::operator=(const InputType& other)
{
	this->myInputType 	= other;
}

void Command::operator=(const sf::Keyboard::Key& other)
{
	this->myKeyCode 	= other;
}
	
void Command::operator=(const sf::Mouse::Button& other)
{
	this->myButton		= other;
}
