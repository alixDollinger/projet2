#include "ProgressBar.h"

ProgressBar::ProgressBar()
{
	max_size = 16;
	value = 16;
}

ProgressBar::ProgressBar(float _max_size, sf::Sprite& sprite)
{
	max_size = _max_size;
	value = _max_size;
	
	rectangle.setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y - sprite.getLocalBounds().height/1.5));
	rectangle.setSize(sf::Vector2f(max_size*sprite.getScale().x, sprite.getLocalBounds().height/1.5));
	rectangle.setFillColor(sf::Color::Red);
}

ProgressBar::~ProgressBar()
{
}

void ProgressBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(rectangle);
}

void ProgressBar::update(sf::Sprite& sprite, float& pv, float& pv_max)
{
	rectangle.setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y - sprite.getLocalBounds().height/1.5));
	float size = max_size * sprite.getScale().x;
	size = size * (pv / pv_max);
	rectangle.setSize(sf::Vector2f(size, sprite.getLocalBounds().height/1.5));

}
