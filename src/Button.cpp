#include"../include/Button.hpp"

#include"../include/MediaBucket.hpp"

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->shape);
	target.draw(this->text);
}

void Button::setFont(sf::Font& font)
{
	this->text.setFont(font);
}

void Button::setSize(sf::Vector2f size)
{
	this->shape.setSize(size);
	this->shape.setOrigin(sf::Vector2f(size.x/2, size.y/2));
}

void Button::setPosition(sf::Vector2f position)
{
	this->shape.setPosition(position);
	this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().width/2, this->text.getLocalBounds().height/2));
	this->text.setPosition(position);
}

void Button::setFillColor(sf::Color color)
{
	this->shape.setFillColor(color);
	this->fill_color = color;
}
	
void Button::setOutlineColor(sf::Color color)
{
	this->text.setColor(color);
	this->shape.setOutlineColor(color);
	this->outline_color = color;
}

void Button::setOutlineThickness(float thickness)
{
	this->shape.setOutlineThickness(thickness);
}

void Button::setText(std::string text)
{
	this->text.setString(text);
	this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().width/2, this->text.getLocalBounds().height/2));
}

void Button::setTextCharacterSize(unsigned int size)
{
	this->text.setCharacterSize(size);
	this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().width/2, this->text.getLocalBounds().height/2));
}
	
void Button::setActive(bool active)
{
	this->active = active;
	if(active == true) {
		this->shape.setOutlineColor(this->fill_color);
		this->shape.setFillColor(this->outline_color);
		this->text.setColor(fill_color);
	} else if(active == false) {
		this->shape.setOutlineColor(this->outline_color);
		this->shape.setFillColor(this->fill_color);
		this->text.setColor(outline_color);
	}
}

bool Button::isActive()
{
	return active;
}
