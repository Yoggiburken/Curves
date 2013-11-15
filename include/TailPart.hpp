#include<SFML/Graphics.hpp>

#ifndef TAIL_PART_HPP
#define TAIL_PART_HPP
class TailPart : public sf::Drawable {
private:
	sf::Time		til_active;
	bool			active;
	sf::CircleShape	part;

	virtual void	draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
					TailPart(sf::CircleShape& shape);
	void			update(sf::Time& elapsed_time);
	
	bool			isActive();
	sf::Vector2f	getPosition();
	
};
#endif
