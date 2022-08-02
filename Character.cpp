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
		if (event.key.code == sf::Keyboard::A)
		{
			m_pressedKeys.key_a = true;
		}
		if (event.key.code == sf::Keyboard::D)
		{
			m_pressedKeys.key_d = true;
		}
		if (event.key.code == sf::Keyboard::W)
		{
			m_pressedKeys.key_w = true;
		}
	}
	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::A)
		{
			m_pressedKeys.key_a = false;
		}
		if (event.key.code == sf::Keyboard::D)
		{
			m_pressedKeys.key_d = false;
		}
		if (event.key.code == sf::Keyboard::W)
		{
			m_pressedKeys.key_w = false;
		}
	}
}

void Character::update(sf::Time dt)
{
	// Sets appropriate vector or rects for animation
	m_isWalking = m_pressedKeys.key_a || m_pressedKeys.key_d;
	m_isJumping = m_pressedKeys.key_w;
	m_isIdle = !(m_isWalking && m_isJumping);

	if (m_isIdle)
	{
		m_isLooping = true;
	}

	if (m_isWalking)
	{
		m_isLooping = true;
	}

	if (m_isJumping)
	{
		m_isLooping = false;
	}

	setDirection();
	setAnimation();
	setRects();
	checkBounds();
	action(dt);
	animate(dt, m_animationRate);
}

void Character::render()
{
	m_sprite.setPosition(m_position);
	m_sprite.setTextureRect(m_currentRect);
}

void Character::setDirection()
{
	if (m_pressedKeys.key_a)
		m_currentDirection = Direction::LEFT;
	if (m_pressedKeys.key_d)
		m_currentDirection = Direction::RIGHT;
}

void Character::setAnimation()
{
	if (m_isWalking)
		m_currentAnimationType = AnimationType::MOVING;
	else if (m_isJumping)
		m_currentAnimationType = AnimationType::JUMPING;
	else
		m_currentAnimationType = AnimationType::IDLE;
}

void Character::setRects()
{
	if (m_isIdle)
		setIdleRects();
	if (m_isWalking)
		setWalkingRects();
	if (m_isJumping)
		setJumpingRects();
}

void Character::checkBounds()
{
	if (m_position.x <= 0)
	{
		m_position.x = 0;
	}
	if (m_position.x + (m_sprite.getLocalBounds().width * m_spriteScaleValues.x) >= 1200)
	{
		m_position.x = 1200 - (m_sprite.getLocalBounds().width * m_spriteScaleValues.x);
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

void Character::animate(sf::Time dt, int animationRate)
{
	if (m_isPlaying) {

		m_timeAccumulationAnimation += dt.asMilliseconds();

		if (m_isLooping)
		{
			while (m_timeAccumulationAnimation >= animationRate)
			{
				m_timeAccumulationAnimation -= animationRate;
				m_rectIndex++;
			}

			if (m_timeAccumulationAnimation == animationRate)
			{
				m_timeAccumulationAnimation -= animationRate;
				m_rectIndex++;
			}

			if (m_rectIndex >= m_textureRects.size())
			{
				m_rectIndex = 0;
			}
		}

		if (!m_isLooping)
		{
			while (m_timeAccumulationAnimation >= animationRate)
			{
				m_timeAccumulationAnimation -= animationRate;
				m_rectIndex++;
			}

			if (m_timeAccumulationAnimation == animationRate)
			{
				m_timeAccumulationAnimation -= animationRate;
				m_rectIndex++;
			}

			if (m_rectIndex >= m_textureRects.size())
			{
				m_isLooping = false;
				m_rectIndex = 0;
			}
		}
	}

	setCurrentRect(m_textureRects[m_rectIndex]);
}

void Character::play()
{
	m_isPlaying = true;
}

void Character::pause()
{
	m_isPlaying = false;
}