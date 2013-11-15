#include"../include/Game.hpp"

extern sf::RenderWindow app;

bool CheckInput(Command& command)
{
	if(command.myInputType == KeyboardInput) {
		return sf::Keyboard::isKeyPressed(command.myKeyCode); 
	} else if(command.myInputType == MouseInput) {
		return sf::Mouse::isButtonPressed(command.myButton);
	}
	return false;
}

void Game::initCommands()
{
	Command 	t_command;
				t_command = KeyboardInput;
				t_command = sf::Keyboard::Left;
	this->commands.push_back(t_command);
				t_command = sf::Keyboard::Right;
	this->commands.push_back(t_command); 
				t_command = sf::Keyboard::A;
	this->commands.push_back(t_command); 
				t_command = sf::Keyboard::D;
	this->commands.push_back(t_command); 
}

int Game::menu()
{
	int players=0;
	sf::Event event;
	while(true)
	{
		while(app.pollEvent(event))
		{
			if(event.type == sf::Event::KeyPressed) {
				if(event.key.code == sf::Keyboard::Escape) {
					app.close();
					return 0;
				}
			}
		}

		app.clear();
		app.display();
	}
}

void Game::run(int players)
{
	sf::View			view;
						view.setSize(static_cast<sf::Vector2f>(app.getSize()));
						view.setCenter(400,300);
	app.setView(view);
	sf::Event			event;
	
	this->initCommands();
	sf::Time	elapsed_time;	
	sf::Clock 	clock;

	while(app.isOpen())
	{
		while(app.pollEvent(event))
		{
			if(event.type == sf::Event::KeyPressed) {
				if(event.key.code == sf::Keyboard::Escape) {
					app.close();
				}
			}
		}
		elapsed_time = clock.restart();
	
		app.clear();
		app.display();
	}
}
