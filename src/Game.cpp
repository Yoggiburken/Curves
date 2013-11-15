#include"../include/Game.hpp"
#include<iostream>

bool TestEvent(Command& command, sf::Event& event)
{
	if(command.myInputType == KeyboardInput) {
		if(event.type == command.myEventType) {
			if(event.key.code == command.myKeyCode) {
				return true;
			}
		}
	} else if(command.myInputType == MouseInput) {
		if(event.type == command.myEventType) {
			if(event.mouseButton.button == command.myButton) {
			return true;
			}
		}
	}
	return false;
}

void Game::initCommands()
{
	Command	t_command;
			t_command = KeyboardInput;
			t_command = sf::Keyboard::Left;
			t_command = sf::Event::KeyPressed;
	this->commands["Left"]	= t_command; 
			t_command = sf::Keyboard::Right;
	this->commands["Right"]	= t_command; 
}


void Game::run()
{
	sf::RenderWindow 	app(sf::VideoMode(800, 600, 32), "Test");
	sf::Event			event;

	bool bindNext = false;
	
	this->initCommands();

	while(app.isOpen())
	{
		while(app.pollEvent(event))
		{
			if(event.type == sf::Event::KeyPressed) {
				if(event.key.code == sf::Keyboard::Escape) {
					app.close();
				}
			}
		
			if(TestEvent(this->commands["Left"], event)) {
				std::cout<<"Left!!!!"<<std::endl;
			}
			if(TestEvent(this->commands["Right"], event)) {
				bindNext = true;
			}
			if(bindNext) {
				if(event.type == sf::Event::KeyPressed) {
					if(event.key.code != sf::Keyboard::Right) {
						this->commands["Left"] = event.key.code;
					}
				}
			}
		}
	}
}
