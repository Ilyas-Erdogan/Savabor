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

	// Set texture details
	m_sprite.setTexture(m_texture);
	m_currentRect = m_textureRects[m_sheetRow][m_sheetCol];
	// Set sprite details
	m_sprite.setOrigin(m_currentRect.width / 2.f, m_currentRect.height / 2.f);
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
		switch (m_event.key.code)
		{
		case sf::Keyboard::D:
			m_isIdle = false;
			m_isWalking = true;
			m_currentDir = Direction::RIGHT;
			break;
		case sf::Keyboard::A:
			m_isIdle = false;
			m_isWalking = true;
			m_currentDir = Direction::LEFT;
			break;
		}
	}
	if (m_event.type == sf::Event::KeyReleased)
	{
		m_isIdle = true;
		m_isWalking = false;
		std::cout << "released" << std::endl;
	}
}

void MrCoin::showNextFrame()
{
	// This function should only be used in while loop 
	// when checking over-accumulation of m_timeAccumulation for column reset
	m_currentRect = m_textureRects[m_sheetRow][m_sheetCol];
	if (m_sheetCol < m_textureRects[m_sheetRow].size() - 1)
	{
		m_sheetCol++;
	}
	else if (m_sheetCol == m_textureRects[m_sheetRow].size() - 1)
	{
		m_sheetCol = 0;
	}

}

void MrCoin::idle(sf::Int32 dt)
{
	if (m_isIdle)
	{
		if (m_currentDir == Direction::LEFT)
		{
			m_sheetRow = 0;
		}
		if (m_currentDir == Direction::RIGHT)
		{
			m_sheetRow = 1;
		}

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
		if (m_currentDir == Direction::LEFT)
		{
			m_sheetRow = 2;
		}
		if (m_currentDir == Direction::RIGHT)
		{
			m_sheetRow = 3;
		}

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
