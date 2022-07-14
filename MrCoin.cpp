#include "MrCoin.h"
#include <iostream>

MrCoin::MrCoin(std::string textureName, sf::Vector2f position, float mass)
	: m_mass {mass}, m_position{position}
{
	// Load texture and check for failure
	if (!m_texture.loadFromFile(textureName.c_str()))
	{
		printf("Could not load file: %s, see error code: LF-100\n", textureName.c_str());
	}

	// Set iterators
	m_rowItr = m_textureRects.begin();
	m_forwardColItr = m_rowItr->begin();
	m_reverseColItr = m_rowItr->rbegin();

	// Set initial rect
	m_currentRect = *m_forwardColItr;

	// Set texture details
	m_sprite.setTexture(m_texture);

	// Set sprite details
	m_sprite.setOrigin(m_texture.getSize().x / 2.f, m_texture.getSize().y / 2.f);
	m_sprite.setPosition(m_position);
	m_sprite.setScale(m_spriteScaleValues);
}

MrCoin::~MrCoin()
{
}

void MrCoin::update(sf::Int32 dt)
{
	// Convert to milliseconds
	m_timeAccumulation += dt;

	// Run animation functions
	idle(dt);
	run(m_event, m_velocity);

	m_sprite.setTextureRect(m_currentRect);
}

void MrCoin::render()
{
	
}

void MrCoin::processEvents(sf::Event event)
{
	// This function should ONLY set the current class's event to the action
	// and change ANIMATION MEMBERS accordingly
	// NOTE: DO NOT CALL ANY ANIMATION FUNCTIONS HERE
	
	m_event = event;

	if (m_event.type == sf::Event::KeyPressed)
	{
		if (m_event.key.code == sf::Keyboard::D || m_event.key.code == sf::Keyboard::A)
		{
			m_isIdle = false;
			m_isWalking = true;
		}
	}
	else if (m_event.type == sf::Event::KeyReleased)
	{
		m_isIdle = true;
		m_isWalking = false;
	}
}

void MrCoin::showNextFrame()
{
	// This function should only be used in while loop 
	// when checking over-accumulation of m_timeAccumulation for column reset
	
	if (m_isIdle)
	{
		if (m_forwardAnim)
		{

			if (m_forwardColItr != m_rowItr->end())
			{
				m_currentRect = *m_forwardColItr;
				m_forwardColItr++;
			}

			if (m_forwardColItr == m_rowItr->end())
			{
				m_forwardAnim = false;
				m_reverseAnim = true;
				m_forwardColItr = m_rowItr->begin();
			}
		}

		if (m_reverseAnim)
		{

			if (m_reverseColItr != m_rowItr->rend())
			{
				m_currentRect = *m_reverseColItr;
				m_reverseColItr++;
			}

			if (m_reverseColItr == m_rowItr->rend())
			{
				m_forwardAnim = true;
				m_reverseAnim = false;
				m_reverseColItr = m_rowItr->rbegin();
			}
		}
	}

	if (m_isWalking)
	{

		if (m_forwardColItr != m_rowItr->end())
		{
			m_currentRect = *m_forwardColItr;
			m_forwardColItr++;
		}

		if (m_forwardColItr == m_rowItr->end())
		{
			m_forwardColItr = m_rowItr->begin();
		}
	}
}
		

void MrCoin::idle(sf::Int32 dt)
{
	if (m_isIdle)
	{
		m_rowItr = m_textureRects.begin();

		while (m_timeAccumulation >= 200)
		{
			// Check for overaccumulation of time
			m_timeAccumulation -= 200;
			showNextFrame();
		}
		
		if (m_timeAccumulation == 200)
		{
			m_timeAccumulation -= 200;
			showNextFrame();
		}
	}
}

void MrCoin::jump(float velocity)
{

}

void MrCoin::run(sf::Event event, float velocity)
{
	if (m_isWalking)
	{
		m_rowItr = m_textureRects.begin() + 1;

		while (m_timeAccumulation >= 200)
		{
			// Check for overaccumulation of time
			m_timeAccumulation -= 200;
			showNextFrame();
		}

		if (m_timeAccumulation == 200)
		{
			m_timeAccumulation -= 200;
			showNextFrame();
		}
	}
}

sf::Sprite MrCoin::getSprite() const
{
	return m_sprite;
}
