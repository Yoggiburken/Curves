#include"../include/Tail.hpp"

void Tail::addPart(sf::CircleShape& part) 
{
	this->parts.push_back(part);
}

void Tail::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(int i=0; i<this->parts.size(); i++) {
		target.draw(this->parts[i]);
	}
}
