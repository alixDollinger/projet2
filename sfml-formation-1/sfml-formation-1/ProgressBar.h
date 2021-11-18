#pragma once
#include <SFML/Graphics.hpp>

class ProgressBar : public sf::Drawable, public sf::Transformable
{
public:
	ProgressBar();
	ProgressBar(float _max_size, sf::Sprite& sprite);
	~ProgressBar();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void update(sf::Sprite& sprite, float& pv, float& pv_max);
protected:
	float max_size;
	float value;
	sf::RectangleShape rectangle;
	
};

