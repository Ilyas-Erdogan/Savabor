#include "Character.h"

Character::Character(const std::string textureName)
{
	// Load texture and check for failure
	if (!m_texture.loadFromFile(textureName.c_str()))
	{
		printf("Could not load file: %s\n", textureName.c_str());
	}

	// Set sprite texture
	m_sprite.setTexture(m_texture);

	// Setup sprite
	m_sprite.setOrigin(m_currentRect.width / 2.f, m_currentRect.height / 2.f);
	m_sprite.setPosition(m_position);
	m_sprite.setScale(m_spriteScaleValues);
}

Character::~Character()
{

}

void Character::setTextureRects(std::vector<sf::IntRect> textureRects)
{
	m_textureRects = textureRects;
}

void Character::setCurrentRect(sf::IntRect currentRect)
{
	m_currentRect = currentRect;
}

sf::Texture Character::getTexture()
{
	return m_texture;
}

sf::Sprite Character::getSprite()
{
	return m_sprite;
}


