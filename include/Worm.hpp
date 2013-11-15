#include<SFML/Graphics.hpp>
#include"Tail.hpp"
#include"Command.hpp"

#ifndef WORM_HPP
#define WORM_HPP

enum Direction {
	Left,
	Right
};

class Worm : public sf::Drawable {
private:
	sf::CircleShape		head;
	Tail				tail;
	
	virtual void 		draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	void				init(sf::Color color, sf::Vector2f position, float rotation);
	void 				update();
	void				turn(Direction dir);
};
#endif
