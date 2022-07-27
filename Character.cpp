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
	m_sprite.setPosition(m_position);
	m_sprite.setScale(m_spriteScaleValues);
}

Character::~Character()
{

}

void Character::processEvents(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::D:
			m_currentDirection = Direction::RIGHT;
			m_currentAnimationType = AnimationType::MOVING_RIGHT;
			setWalkVariables();
			break;
		case sf::Keyboard::A:
			m_currentDirection = Direction::LEFT;
			m_currentAnimationType = AnimationType::MOVING_LEFT;
			setWalkVariables();
			break;
		}
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::D:
		case sf::Keyboard::A:
			m_currentAnimationType = AnimationType::IDLE;
			setIdleVariables();
			break;
		}
	}
}

void Character::checkBounds()
{
	//printf("%f\n", m_position.x + (m_sprite.getLocalBounds().width * m_spriteScaleValues.x));
	if (m_position.x <= 0)
	{
		m_position.x = 0;
	}
	if (m_position.x + (m_sprite.getLocalBounds().width * m_spriteScaleValues.x) >= 1200)
	{
		m_position.x = 1200 - (m_sprite.getLocalBounds().width * m_spriteScaleValues.x);
		printf("YES\n");
	}
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

void Character::play()
{
	m_isPlaying = true;
}

void Character::pause()
{
	m_isPlaying = false;
}

void Character::setIdleVariables()
{
	m_isIdle = true;
	m_isWalking = false;
	m_isJumping = false;
}

void Character::setWalkVariables()
{
	m_isIdle = false;
	m_isWalking = true;
	m_isJumping = false;
}

void Character::setJumpVariables()
{
	m_isIdle = false;
	m_isWalking = false;
	m_isJumping = true;
}
