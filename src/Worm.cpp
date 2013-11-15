#include"../include/Worm.hpp"

#include<cmath>

const float WORM_VELOCITY = 200;

extern sf::Time elapsed_time;

void Worm::init(sf::Color color, sf::Vector2f position, float rotation)
{
	this->head.setRadius(2);
	this->head.setFillColor(color);
	this->head.setPosition(position);
	this->head.setRotation(rotation);
}

void Worm::update()
{
	this->tail.addPart(this->head);
	float rotation = this->head.getRotation();
	this->head.move(sf::Vector2f(WORM_VELOCITY*cos(rotation), WORM_VELOCITY*sin(rotation))*elapsed_time.asSeconds());
}

void Worm::turn(Direction dir)
{
	if(dir == Left) {
		this->head.setRotation(this->head.getRotation()+100*elapsed_time.asSeconds());
	} else if(dir == Right) {
		this->head.setRotation(this->head.getRotation()-100*elapsed_time.asSeconds());
	}
}

void Worm::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->head);
	target.draw(this->tail);
}
