#pragma once
#include <SFML/Graphics.hpp>
class Entity : public sf::Drawable, public sf::Transformable
{
public:
	Entity(sf::Texture& texture, std::string code, int scale, int tile_size);
	~Entity();


	
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void update();
	void collision_border(int scale, int tile_size);
	void anim_chara(sf::Texture& texture, sf::Clock& clock, int tile_size);
	sf::Sprite& getSprite() { return sprite; };
	sf::Vector2f getSpeed() { return speed; };

protected:
	sf::Sprite sprite;
	sf::Vector2f speed = { 0.f,0.f };
	std::string code;
	int pv;
	// 0 down; 1 up; 2 right; 3 left
	int direction_anim = 0;
	//0 arret; 1 right; 2 left
	int state_anime = 0;
};
