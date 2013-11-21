#include<SFML/Graphics.hpp>
#include"Command.hpp"
#include"TailPart.hpp"

#ifndef WORM_HPP
#define WORM_HPP


class Worm : public sf::Drawable {
private:
	sf::CircleShape					head;
	std::vector<TailPart>			tail;
	sf::Time						next_tailPart;	
	Command							turn_left;
	Command							turn_right;
	std::string						turn_left_string;
	std::string						turn_right_string;
			
	virtual void 					draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void							updateTailParts(sf::Time& elapsed_time);
public:
	enum Direction {
		Left,
		Right
	};
	void							init(sf::Color color, sf::Vector2f position, float rotation);
	void 							update(sf::Time& elapsed_time);
	void							turn(Direction dir, sf::Time& elapsed_time);
	void							addTailPart(sf::CircleShape& shape);
	
	void							setCommand(Direction, sf::Keyboard::Key);
	void							setCommandString(Direction, std::string str);
		
	bool							headCollision(Worm& worm);
	bool							tailCollision(Worm& worm);

	sf::Vector2f					getHeadPosition();
};
#endif
