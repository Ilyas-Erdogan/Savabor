#include "MrCoin.h"

MrCoin::MrCoin() : Character("Assets/graphics/Mr. Coin.png")
{
	setTextureRects(m_idleLeft);
	m_position = sf::Vector2f(500.f, 500.f);
}

MrCoin::~MrCoin()
{

}


void MrCoin::update(sf::Time dt)
{
	// Sets appropriate vector or rects for animation
	if (m_currentDirection == Direction::LEFT)
	{
		if (m_currentAnimationType == AnimationType::IDLE)
		{
			setTextureRects(m_idleLeft);
			m_isLooping = true;
		}
		if (m_currentAnimationType == AnimationType::MOVING_LEFT)
		{
			setTextureRects(m_walkingLeft);
			m_isLooping = true;
		}
	}

	if (m_currentDirection == Direction::RIGHT)
	{
		if (m_currentAnimationType == AnimationType::IDLE)
		{
			setTextureRects(m_idleRight);
			m_isLooping = true;
		}
		if (m_currentAnimationType == AnimationType::MOVING_RIGHT)
		{
			setTextureRects(m_walkingRight);
			m_isLooping = true;
		}
	}

	checkBounds();
	action(dt);
	animate(dt);
}
void MrCoin::render()
{
	m_sprite.setPosition(m_position);
	m_sprite.setTextureRect(m_currentRect);
}

void MrCoin::animate(sf::Time dt)
{
	if (m_isPlaying) {

		m_timeAccumulationAnimation += dt.asMilliseconds();

		if (m_isLooping)
		{
			while (m_timeAccumulationAnimation >= 250)
			{
				m_timeAccumulationAnimation -= 250;
				m_rectIndex++;
			}

			if (m_timeAccumulationAnimation == 250)
			{
				m_timeAccumulationAnimation -= 250;
				m_rectIndex++;
			}

			if (m_rectIndex >= m_textureRects.size())
			{
				m_rectIndex = 0;
			}
		}
	}

	setCurrentRect(m_textureRects[m_rectIndex]);
}

void MrCoin::action(sf::Time dt)
{
	// PURPOSE: Change movement according to action and direction

	m_timeAccumulationAction += dt.asSeconds();
	
	if (m_isIdle)
	{
		m_velocity = 0.f;
	}

	if (m_isWalking)
	{
		// Accelerate velocity
		m_velocity += m_acceleration;

		// Change x-coordinate according to direction
		if (m_currentDirection == Direction::LEFT)
		{
			m_position.x -= m_velocity * m_timeAccumulationAction;
		}
		if (m_currentDirection == Direction::RIGHT)
		{
			m_position.x += m_velocity * m_timeAccumulationAction;
		}

		// Change acceleration (check max velocity)
		if (m_velocity >= 500)
		{
			m_acceleration = 0;
		}
		else
		{
			m_acceleration = 5.f;
		}
	}

	if (m_isJumping)
	{

	}
	
	m_timeAccumulationAction = 0;
}
