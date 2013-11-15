#include<SFML/Graphics.hpp>
#include"Tail.hpp"
#include"Command.hpp"

#ifndef WORM_HPP
#define WORM_HPP
class Worm : public sf::Drawable {
private:
	sf::CircleShape		head;
	Tail				tail;
	
	virtual void 		draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	void 				update();	
};
#endif
