#include"../include/TailPart.hpp"


TailPart::TailPart(sf::CircleShape& shape)
{
	this->part = shape;
	this->til_active = sf::seconds(0.2);
	this->active = false;
}

void TailPart::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->part);
}

void TailPart::update(sf::Time& elapsed_time)
{
	this->til_active -= elapsed_time;
	if(this->til_active.asSeconds() <= 0) {
		this->active = true;
	}
}

bool TailPart::isActive()
{
	return this->active;
}

sf::Vector2f TailPart::getPosition()
{
	return this->part.getPosition();
}
