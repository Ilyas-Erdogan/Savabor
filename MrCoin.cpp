#include "MrCoin.h"

MrCoin::MrCoin() : Character("Assets/graphics/Mr. Coin.png")
{
	setTextureRects(m_idleLeft);
}

MrCoin::~MrCoin()
{

}

void MrCoin::processEvents(sf::Event event)
{
	m_event = event;
	if (m_event.type == sf::Event::KeyPressed)
	{
		switch (m_event.key.code)
		{
		case sf::Keyboard::D:
			//printf("RIGHT\n");
			m_currentDirection = Direction::RIGHT;
			m_currentAnimationType = AnimationType::MOVING_RIGHT;
			m_isLooping = true;
			break;
		case sf::Keyboard::A:
			//printf("LEFT\n");
			m_currentDirection = Direction::LEFT;
			m_currentAnimationType = AnimationType::MOVING_LEFT;
			m_isLooping = true;
			break;
		}
	}
	else if (m_event.type == sf::Event::KeyReleased)
	{
		switch (m_event.key.code)
		{
		case sf::Keyboard::D:
		case sf::Keyboard::A:
			m_currentAnimationType = AnimationType::IDLE;
			break;
		}
	}
}
void MrCoin::update(sf::Int32 dt)
{
	m_timeAccumulation += dt;

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

	play(dt);
}
void MrCoin::render()
{
	m_sprite.setTextureRect(m_currentRect);
}

void MrCoin::play(sf::Int32 dt)
{
	if (m_isPlaying && m_isLooping)
	{
		while (m_timeAccumulation >= 250)
		{
			m_timeAccumulation -= 250;
			m_rectIndex++;
		}

		if (m_timeAccumulation == 250)
		{
			m_timeAccumulation -= 250;
			m_rectIndex++;
		}
		if (m_rectIndex >= m_textureRects.size())
		{
			m_rectIndex = 0;
		}
	}


	setCurrentRect(m_textureRects[m_rectIndex]);
}

void MrCoin::pause()
{
}
