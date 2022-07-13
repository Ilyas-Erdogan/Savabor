#pragma once

#include <SFML/Graphics.hpp>
#include <array>

class Animation
{
private:
	sf::Sprite sprite;
	std::array<std::array<sf::IntRect, 3>, 2> spriteSheet; // will hold address of spritesheet from PLAYER class
	sf::IntRect currentRect;

public:
	Animation(sf::Sprite &p_sprite, const std::array<std::array<sf::IntRect, 3>, 2> &p_spriteSheet);
	~Animation();

	void update();
	void render();
};

