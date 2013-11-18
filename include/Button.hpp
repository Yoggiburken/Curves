#include<SFML/Graphics.hpp>

#ifndef BUTTON_HPP
#define BUTTON_HPP
class Button : public sf::Drawable {
private:
	sf::RectangleShape	shape;
	sf::Text			text;
	
	sf::Color			fill_color;
	sf::Color			outline_color;
		
	bool				active;

	virtual void		draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	void				setPosition(sf::Vector2f position);
	void				setSize(sf::Vector2f size);
	void				setFillColor(sf::Color color);
	
	void				setOutlineColor(sf::Color color);
	void				setOutlineThickness(float thickness);

	void				setFont(sf::Font& font);
	void				setText(std::string text);
	void				setTextCharacterSize(unsigned int size);
		
	void				setActive(bool active);

	bool				isActive();
};
#endif
