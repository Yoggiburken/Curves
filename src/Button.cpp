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
{
	this->shape.setPosition(position);
	this->text.setPosition(position);
}

void Button::setFillColor(sf::Color color)
{
	this->shape.setFillColor(color);
}
	
void Button::setOutlineColor(sf::Color color)
{
	this->shape.setOutlineColor(color);
}

void Button::setOutlineThickness(float thickness)
{
	this->shape.setOutlineThickness(thickness);
}

void Button::setText(std::string text)
{
	this->text.setString(text);
}

void Button::setTextColor(sf::Color color)
{
	this->text.setColor(color);
}
	
void Button::setActive(bool active)
{
	this->active = active;
}

bool Button::isActive()
{
	return active;
}
