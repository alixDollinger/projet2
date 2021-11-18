#pragma once
#include <SFML/Graphics.hpp>
#include "ProgressBar.h"
class Entity : public sf::Drawable, public sf::Transformable
{
public:
	Entity(sf::Texture& texture, std::string code, int scale, int tile_size);
	~Entity();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void update();
	void collision_border(int& scale, int& tile_size, int& map_max_x, int& map_max_y);
	void anim_chara(sf::Texture& texture, sf::Clock& clock, int tile_size);
	sf::Sprite& getSprite() { return sprite; };
	sf::Vector2f getSpeed() { return speed; };
	bool& getIs_it() { return is_hit; };
	void setIs_it(bool _is_it);
	bool& getInvincible() { return invincible; };
	void invinsibiliter();
	void take_damage(int damage) { pv -= damage; };
	bool is_alive();
protected:
	sf::Sprite sprite;
	sf::Vector2f speed = { 0.f,0.f };
	std::string code;
	bool is_hit = false;
	bool invincible = false;
	sf::Clock invincible_timing;
	float invinsible_time = 1;
	float pv;
	float pv_max;
	// 0 down; 1 up; 2 right; 3 left
	int direction_anim = 0;
	//0 arret; 1 right; 2 left
	int state_anime = 0;
	ProgressBar hp_bar;
};
