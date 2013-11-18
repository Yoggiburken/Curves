#include"../include/Game.hpp"

extern sf::RenderWindow app;

Game::Game()
{
	this->mediabucket.loadFontFromFile("resources/VT323-Regular.ttf");
}

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
	int i=0;
	Command 	t_command;
				t_command = KeyboardInput;
	if(number_of_players > i++) {
				t_command = sf::Keyboard::Left;
	this->commands.push_back(t_command);
				t_command = sf::Keyboard::Right;
	this->commands.push_back(t_command); 
	}
	if(number_of_players > i++) {
				t_command = sf::Keyboard::A;
	this->commands.push_back(t_command);
				t_command = sf::Keyboard::D;
	this->commands.push_back(t_command); 
	}
	if(number_of_players > i++) {
	}
	if(number_of_players > i++) {
	}
	if(number_of_players > i++) {
	}
	if(number_of_players > i++) {
	}
}

void Game::initMenuButtons()
{
	Button 	t_button;
			t_button.setFont(this->mediabucket.getFont("VT323-Regular.ttf"));
			t_button.setTextCharacterSize(30);	
			t_button.setSize(sf::Vector2f(200, 100));
			t_button.setFillColor(sf::Color::Black);
			t_button.setOutlineColor(sf::Color::White);
			t_button.setOutlineThickness(5);

			t_button.setText("Play");
			t_button.setPosition(sf::Vector2f(app.getSize().x/2, app.getSize().y/2) + sf::Vector2f(0, -60));
	this->menu_buttons.push_back(t_button);
			t_button.setText("Exit");
			t_button.setPosition(sf::Vector2f(app.getSize().x/2, app.getSize().y/2) + sf::Vector2f(0, 60));
	this->menu_buttons.push_back(t_button);
}

Game::Menu_RS Game::menu()
{
	this->number_of_players = 0;
	this->initMenuButtons();
	sf::Event event;
	while(true)
	{
		while(app.pollEvent(event))
		{
			if(event.type == sf::Event::KeyPressed) {
				if(event.key.code == sf::Keyboard::Escape) {
					app.close();
					return Game::Exit;
				}
			}
		}

		app.clear();
		for(int i=0; i<this->menu_buttons.size(); i++) {
			app.draw(this->menu_buttons[i]);
		}
		app.display();
	}
}

void Game::run()
{
	srand(time(NULL));
	sf::View			view;
						view.setSize(static_cast<sf::Vector2f>(app.getSize()));
						view.setCenter(view.getSize().x/2, view.getSize().y/2);
	app.setView(view);
	sf::Event			event;
	
	this->players.resize(number_of_players, Worm());	
	
	for(int i=0; i<number_of_players; i++) {
		this->players[i].init(sf::Color(rand()%256, rand()%256, rand()%256), sf::Vector2f(rand()%600+100, rand()%400+100), rand()%360);
	}
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
		
		for(int i=0; i<this->commands.size()/2; i++) {
			if(CheckInput(this->commands[2*i])) {
				this->players[i].turn(Worm::Left, elapsed_time);
			}
			if(CheckInput(this->commands[1+2*i])) {
				this->players[i].turn(Worm::Right, elapsed_time);
			}
		}
		
		for(int i=0; i<this->players.size(); i++) {
			this->players[i].update(elapsed_time);
		}
			
		app.clear();
		for(int i=0; i<this->players.size(); i++) {
			app.draw(this->players[i]);
		}
		app.display();
	}
}
