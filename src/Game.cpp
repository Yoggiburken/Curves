#include"../include/Game.hpp"

#include<sstream>

extern sf::RenderWindow app;

std::string itos(int i)
{
	std::stringstream ss;
	ss<<i;
	return ss.str();
}

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

void Game::initMainMenuButtons()
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
	this->initMainMenuButtons();

	int active_button = 0;
	this->menu_buttons[active_button].setActive(true);

	sf::Event event;
	while(true)
	{
		while(app.pollEvent(event))
		{
			if(event.type == sf::Event::KeyPressed) {
				if(event.key.code == sf::Keyboard::Escape) {
					app.close();
					return Game::Exit;
				} else if(event.key.code == sf::Keyboard::Up) {
					this->menu_buttons[active_button].setActive(false);
					active_button++;
					if(active_button > 1) {
						active_button = 0;
					}
					this->menu_buttons[active_button].setActive(true);
				} else if(event.key.code == sf::Keyboard::Down) {
					this->menu_buttons[active_button].setActive(false);
					active_button--;
					if(active_button < 0) {
						active_button = 1;
					}
					this->menu_buttons[active_button].setActive(true);
				} else if(event.key.code == sf::Keyboard::Return) {
					this->menu_buttons.clear();
					if(active_button == 0) {
						return Game::Play;
					} else if(active_button == 1) {
						return Game::Exit;
					}
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

void Game::initPreparationMenu()
{
	Button 	t_button;
			t_button.setFont(this->mediabucket.getFont("VT323-Regular.ttf"));
			t_button.setTextCharacterSize(30);	
			t_button.setSize(sf::Vector2f(200, 100));
			t_button.setFillColor(sf::Color::Black);
			t_button.setOutlineColor(sf::Color::White);
			t_button.setOutlineThickness(5);

	this->number_of_players = 0;
			std::string number_of_players_string = "Players: " + itos(this->number_of_players);
			t_button.setText(number_of_players_string);
			t_button.setPosition(sf::Vector2f(app.getSize().x/2, app.getSize().y/2));
	this->menu_buttons.push_back(t_button);
}

void Game::preparationMenu()
{
	this->initPreparationMenu();
	int active_button = 0;

	sf::Event event;

	while(true)
	{
		while(app.pollEvent(event))
		{
			if(event.type == sf::Event::KeyPressed) {
				if(event.key.code == sf::Keyboard::Escape) {
					this->menu_buttons.clear();
					return;
				} else if(event.key.code == sf::Keyboard::Up) {
					this->menu_buttons[active_button].setActive(false);
					active_button++;
					if(active_button == this->menu_buttons.size()) {
						active_button = 0;
					}
					this->menu_buttons[active_button].setActive(true);
				} else if(event.key.code == sf::Keyboard::Down) {
					this->menu_buttons[active_button].setActive(false);
					active_button--;
					if(active_button < 0) {
						active_button = this->menu_buttons.size()-1;
					}
					this->menu_buttons[active_button].setActive(true);
				} else if(active_button == 0) {
					if(event.key.code == sf::Keyboard::Left) {
						if(number_of_players > 0) {
							this->number_of_players--;
							this->menu_buttons.erase(this->menu_buttons.begin() + this->menu_buttons.size()-1);
							this->players.erase(this->players.begin() + this->players.size()-1);
							this->menu_buttons[0].setText("Players: " + itos(number_of_players));
						}
					} else if(event.key.code == sf::Keyboard::Right) {
						if(number_of_players < 8) {
							this->number_of_players++;
							Button 	t_button;
									t_button.setFont(this->mediabucket.getFont("VT323-Regular.ttf"));
									t_button.setTextCharacterSize(30);	
									t_button.setSize(sf::Vector2f(190, 90));
									t_button.setFillColor(sf::Color::Black);
									t_button.setOutlineColor(sf::Color::White);
									t_button.setOutlineThickness(5);
									t_button.setText("Player" + itos(number_of_players));
									sf::Vector2f position;
									
									if(this->number_of_players > 4) {
										position.y =  50+ app.getSize().y-100;
										position.x = 100+200*(this->number_of_players-5);
									} else {
										position.y = -50 + app.getSize().y-100;
										position.x = 100+200*(this->number_of_players-1);
									}

									t_button.setPosition(position);
							this->menu_buttons.push_back(t_button);
							this->players.push_back(Worm());

							this->menu_buttons[0].setText("Players: " + itos(number_of_players));
						}
					}
				}
				else if(event.key.code == sf::Keyboard::Return && active_button > 0 && this->players.size() > 0) {
					bool bind_key_left = true;
					bool bind_key_right = true;
					bool has_set_string = false;
					bool has_set_key 	= false;
					while(bind_key_left)
					{
						while(app.pollEvent(event))
						{
							if(event.type == sf::Event::KeyPressed) {
								this->players[(active_button-1)].setCommand(Worm::Left, event.key.code);
								has_set_key = true;
							}
							if(event.type == sf::Event::TextEntered) {
								sf::String str;
								str = event.text.unicode;
								this->players[(active_button-1)].setCommandString(Worm::Left, str.toAnsiString());
								has_set_string = true;
							}
						}

						if(has_set_string && has_set_key) {
							bind_key_left = false;
						}
					}
					has_set_string 	= false;
					has_set_key		= false;
					while(bind_key_right)
					{
						while(app.pollEvent(event))
						{
							if(event.type == sf::Event::KeyPressed) {
								this->players[(active_button-1)].setCommand(Worm::Right, event.key.code);
								has_set_key = true;
							}
							if(event.type == sf::Event::TextEntered) {
								sf::String str;
								 str = event.text.unicode;
								this->players[(active_button-1)].setCommandString(Worm::Right, str.toAnsiString());
								has_set_string = true;
							}
						}

						if(has_set_string && has_set_key) {
							bind_key_right = false;
						}
					}
				} else if(event.key.code == sf::Keyboard::Return) {
					this->menu_buttons.clear();
					return;
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
	this->number_of_players = 0;
	this->players.clear();
	this->preparationMenu();
	if(this->number_of_players == 0) {
		return;
	}

	srand(time(NULL));
	sf::View			view;
						view.setSize(static_cast<sf::Vector2f>(app.getSize()));
						view.setCenter(view.getSize().x/2, view.getSize().y/2);
	app.setView(view);
	sf::Event			event;
	
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
					return;
				}
			}
		}
		elapsed_time = clock.restart();
		
		for(int i=0; i<this->commands.size()/2; i++) {
			this->players[i].update(elapsed_time);
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
