#include "ProgressBar.h"

ProgressBar::ProgressBar()
{
	//Texture texture;
	texture.loadFromFile("foresttiles2-t.png");


}

ProgressBar::~ProgressBar()
{
}

void ProgressBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(front);
}
