#include "MrCoin.h"

MrCoin::MrCoin() : Character("Assets/graphics/Mr. Coin.png")
{
	setTextureRects(m_idleLeft);
	m_position = sf::Vector2f(500.f, 500.f);
}

MrCoin::~MrCoin()
{

}

void MrCoin::action(sf::Time dt)
{
	// PURPOSE: Change movement according to action and direction
	m_timeAccumulationAction += dt.asSeconds();

	if (m_isIdle)
	{
		idle();
	}
	if (m_isWalking)
	{
		walking();
	}
	if (m_isJumping)
	{
		jumping();
	}
	
	m_timeAccumulationAction = 0;
}

void MrCoin::setIdleRects()
{
	m_animationRate = 250;
	if (m_currentDirection == Direction::LEFT)
	{
		setTextureRects(m_idleLeft);
	}
	if (m_currentDirection == Direction::RIGHT)
	{
		setTextureRects(m_idleRight);
	}
}

void MrCoin::setWalkingRects()
{
	m_animationRate = 100;
	if (m_currentDirection == Direction::LEFT)
	{
		setTextureRects(m_walkingLeft);
	}
	if (m_currentDirection == Direction::RIGHT)
	{
		setTextureRects(m_walkingRight);
	}
}

void MrCoin::setJumpingRects()
{
	if (m_currentDirection == Direction::LEFT)
	{
		setTextureRects(m_jumpingLeft);
	}
	if (m_currentDirection == Direction::RIGHT)
	{
		setTextureRects(m_jumpingRight);
	}
}

void MrCoin::idle()
{
	m_currentVelocity = m_initialVelocity;
}

void MrCoin::walking()
{
	printf("%f\n", m_timeAccumulationAction);
	// Accelerate velocity
	m_currentVelocity.x += m_acceleration.x;

	// Change x-coordinate according to direction
	if (m_currentDirection == Direction::LEFT)
	{
		m_position.x -= m_currentVelocity.x * m_timeAccumulationAction;
	}
	if (m_currentDirection == Direction::RIGHT)
	{
		m_position.x += m_currentVelocity.x * m_timeAccumulationAction;
	}

	// Change acceleration (check max velocity)
	if (m_currentVelocity.x >= (2 * m_initialVelocity.x))
	{
		m_acceleration.x = 0;
	}
	else
	{
		m_acceleration.x = 500.f;
	}
}

void MrCoin::jumping()
{	

}
