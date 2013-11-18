#include"../include/Button.hpp"

#include"../include/MediaBucket.hpp"

extern MediaBucket mediabucket;

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->shape);
	target.draw(this->text);
}

Button::Button()
{
	this->text.setFont(mediabucket.getFont(""));
}

void Button::setSize(sf::Vector2f size)
{
	this->shape.setSize(size);
	this->shape.setOrigin(sf::Vector2f(size.x/2, size.y/2));
}

void Button::setPosition(sf::Vector2f position)
{}

void Button::setFillColor(sf::Color color)
{}
	
void Button::setOutlineColor(sf::Color color)
{}

void Button::setOutlineThickness(float thickness)
{}

void Button::setText(std::string text)
{}

void Button::setTextColor(sf::Color color)
{}
	
void Button::setActive(bool active)
{}

bool Button::isActive()
{
	return active;
}
