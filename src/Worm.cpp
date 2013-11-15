#include"../include/Worm.hpp"

#include<cmath>

const float WORM_VELOCITY = 200;

extern sf::Time elapsed_time;

void Worm::update()
{
	this->tail.addPart(this->head);
	float rotation = this->head.getRotation();
	this->head.move(sf::Vector2f(WORM_VELOCITY*cos(rotation), WORM_VELOCITY*sin(rotation))*elapsed_time.asSeconds());
}

void Worm::turn(Direction dir)
{
	if(dir == Left) {
	} else if(dir == Right) {
	}
}

void Worm::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->head);
	target.draw(this->tail);
}
