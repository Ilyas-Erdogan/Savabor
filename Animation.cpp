#include "Animation.h"


Animation::Animation(sf::Sprite& p_sprite, const std::array<std::array<sf::IntRect, 3>, 2>& p_spriteSheet)
	: sprite { p_sprite }, spriteSheet { p_spriteSheet }
{
	currentRect = spriteSheet[0][0];
}

Animation::~Animation()
{
}

void Animation::update()
{

}

void Animation::render()
{
	sprite.setTextureRect(currentRect);
}