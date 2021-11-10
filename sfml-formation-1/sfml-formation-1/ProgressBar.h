#pragma once
#include <SFML/Graphics.hpp>

class ProgressBar : public sf::Drawable, public sf::Transformable
{
public:

	ProgressBar();
	~ProgressBar();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
	float max_size;
	float value;

	sf::Texture texture;
	sf::Sprite front;
};

