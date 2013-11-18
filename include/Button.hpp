#include<SFML/Graphics.hpp>

#ifndef BUTTON_HPP
#define BUTTON_HPP
class Button : public sf::Drawable {
private:
	sf::RectangleShape	shape;
	sf::Text			text;
	
	bool				active;

	virtual void		draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
						Button();
	
	void				setPosition(sf::Vector2f position);
	void				setSize(sf::Vector2f size);
	void				setFillColor(sf::Color color);
	
	void				setOutlineColor(sf::Color color);
	void				setOutlineThickness(float thickness);

	void				setText(std::string text);
	void				setTextColor(sf::Color color);
	
	void				setActive(bool active);

	bool				isActive();
};
#endif
