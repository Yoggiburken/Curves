#include"../include/Game.hpp"

extern sf::Time elapsed_time;

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


void Game::run()
{
	sf::RenderWindow 	app(sf::VideoMode(800, 600, 32), "Test");
	sf::View			view;
						view.setSize(static_cast<sf::Vector2f>(app.getSize()));
						view.setCenter(400,300);
	app.setView(view);
	sf::Event			event;
	
	Worm				worm1, worm2;
						worm1.init(sf::Color::Red, sf::Vector2f(100,100), 0);
						worm2.init(sf::Color::Blue, sf::Vector2f(700, 500), 180);

	this->initCommands();
	
	sf::Clock clock;

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
	
		if(CheckInput(this->commands[0])) {
			worm1.turn(Left);
		}
		if(CheckInput(this->commands[1])) {
			worm1.turn(Right);
		}
		if(CheckInput(this->commands[2])) {
			worm2.turn(Left);
		}
		if(CheckInput(this->commands[3])) {
			worm2.turn(Right);
		}
		worm1.update();
		worm2.update();

		if(worm1.headCollision(worm2) || worm1.tailCollision(worm2) || worm1.tailCollision(worm1)) {
			return;
		}
		if(worm2.headCollision(worm1) || worm2.tailCollision(worm1) || worm2.tailCollision(worm2)) {
			return;
		}

		app.clear();
		app.draw(worm1);
		app.draw(worm2);
		app.display();
	}
}
