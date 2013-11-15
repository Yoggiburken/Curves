#include<SFML/Graphics.hpp>
#include"Command.hpp"
#include"TailPart.hpp"

#ifndef WORM_HPP
#define WORM_HPP

enum Direction {
	Left,
	Right
};

class Worm : public sf::Drawable {
private:
	sf::CircleShape					head;
	std::vector<TailPart>			tail;
	sf::Time						next_tailPart;	
	virtual void 					draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void							updateTailParts();
public:
	void							init(sf::Color color, sf::Vector2f position, float rotation);
	void 							update();
	void							turn(Direction dir);
	void							addTailPart(sf::CircleShape& shape);
	
	bool							headCollision(Worm& worm);
	bool							tailCollision(Worm& worm);

	sf::Vector2f					getHeadPosition();
};
#endif
