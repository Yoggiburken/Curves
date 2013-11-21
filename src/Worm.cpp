#include"../include/Worm.hpp"

#include<cmath>

const float WORM_VELOCITY = 60;
const float WORM_HEAD_RADIUS = 2;
const float WORM_ROTATION_SPEED = 300;
const float PI = 3.1415;

void Worm::init(sf::Color color, sf::Vector2f position, float rotation)
{
	this->head.setRadius(WORM_HEAD_RADIUS);
	this->head.setOrigin(sf::Vector2f(this->head.getLocalBounds().width/2, this->head.getLocalBounds().height/2));
	this->head.setFillColor(color);
	this->head.setPosition(position);
	this->head.setRotation(rotation);
	this->next_tailPart = sf::seconds(0.02);
}

void Worm::update(sf::Time& elapsed_time)
{
	if(sf::Keyboard::isKeyPressed(this->turn_left.myKeyCode)) {
		this->turn(Worm::Left, elapsed_time);
	}
	if(sf::Keyboard::isKeyPressed(this->turn_right.myKeyCode)) {
		this->turn(Worm::Right, elapsed_time);
	}
	this->next_tailPart -= elapsed_time;
	if(this->next_tailPart.asSeconds() <= 0) {
		this->addTailPart(this->head);
		this->next_tailPart = sf::seconds(0.02);
	}
	float rotation = this->head.getRotation();
	this->head.move(sf::Vector2f(WORM_VELOCITY*cos(rotation * PI/180), WORM_VELOCITY*sin(rotation*PI/180))*elapsed_time.asSeconds());
	this->updateTailParts(elapsed_time);
}

void Worm::updateTailParts(sf::Time& elapsed_time)
{
	for(int i=0; i<tail.size(); i++) {
		if(!this->tail[i].isActive()) {
			this->tail[i].update(elapsed_time);
		}
	}
}

void Worm::addTailPart(sf::CircleShape& shape)
{
	this->tail.push_back(TailPart(shape));
}

void Worm::turn(Direction dir, sf::Time& elapsed_time)
{
	if(dir == Left) {
		float rotation = this->head.getRotation() -WORM_ROTATION_SPEED*elapsed_time.asSeconds();
		this->head.setRotation(rotation);
	} else if(dir == Right) {
		float rotation = this->head.getRotation() +WORM_ROTATION_SPEED*elapsed_time.asSeconds();
		this->head.setRotation(rotation);
	}
}

void Worm::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->head);
	for(int i=0; i<tail.size(); i++) {
		target.draw(tail[i]);
	}
}

void Worm::setCommand(Worm::Direction direction, sf::Keyboard::Key key)
{
	if(direction == Worm::Left) {
		this->turn_left = key;
	} else if(direction == Worm::Right) {
		this->turn_right = key;
	}
}

void Worm::setCommandString(Worm::Direction direction, std::string str)
{
	if(direction == Worm::Left) {
		this->turn_left_string = str;
	} else if(direction == Worm::Right) {
		this->turn_right_string = str;
	}
}

bool Worm::headCollision(Worm& worm)
{
	sf::Vector2f this_pos = this->getHeadPosition();
	sf::Vector2f worm_pos = worm.getHeadPosition();
	float distance = sqrt(pow(this_pos.x - worm_pos.x, 2)+pow(this_pos.y - worm_pos.y, 2));
	if(distance < WORM_HEAD_RADIUS*2) {
		return true;
	}
	return false;
}

bool Worm::tailCollision(Worm& worm)
{
	for(int i=0; i<this->tail.size(); i++) {
		if(this->tail[i].isActive()) {
			sf::Vector2f this_pos = this->tail[i].getPosition();
			sf::Vector2f worm_pos = worm.getHeadPosition();
			float distance = sqrt(pow(this_pos.x - worm_pos.x, 2)+pow(this_pos.y - worm_pos.y, 2));
			if(distance < WORM_HEAD_RADIUS*2) {
				return true;
			}
		}
	}
	return false;
}

sf::Vector2f Worm::getHeadPosition()
{
	return this->head.getPosition();
}
