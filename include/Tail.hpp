#include<vector>
#include<SFML/Graphics.hpp>

#ifndef TAIL_HPP
#define TAIL_HPP
class Tail : public sf::Drawable {
private:
	std::vector<sf::Shape*>		parts;

	virtual void 				draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	void						addPart(sf::Shape* part);
};
#endif
