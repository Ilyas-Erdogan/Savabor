#pragma once

#include "Animation.h"
#include <iterator>
#include "SFML/Graphics.hpp"

class MrCoin
{
public:
	MrCoin(std::string textureName, sf::Vector2f position, float mass);
	~MrCoin();

	void update(sf::Int32 dt);
	void render();
	void processEvents(sf::Event event);
	void showNextFrame();

	void idle(sf::Int32 dt);
	void jump(float velocity);
	void run(sf::Event, float velocity);

	sf::Sprite getSprite() const;

private:
	sf::Texture m_texture;
	const std::vector<std::vector<sf::IntRect>> m_textureRects
	{ {
		{ sf::IntRect(0, 0, 32, 32), sf::IntRect(32, 0, 32, 32), sf::IntRect(64, 0, 32, 32), sf::IntRect(96, 0, 32, 32)},
		{ sf::IntRect(128, 0, 32, 32), sf::IntRect(160, 0, 32, 32), sf::IntRect(192, 0, 32, 32), sf::IntRect(224, 0, 32, 32)},
		{ sf::IntRect(0, 32, 32, 32), sf::IntRect(32, 32, 32, 32), sf::IntRect(64, 32, 32, 32) },
		{ sf::IntRect(128, 32, 32, 32), sf::IntRect(160, 32, 32, 32), sf::IntRect(192, 32, 32, 32) }
	} };
	int m_sheetRow{ 0 };
	int m_sheetCol{ 0 };
	sf::IntRect m_currentRect{m_textureRects[0][0]};

	sf::Sprite m_sprite;
	sf::Vector2f m_spriteScaleValues{ 4.f, 4.f };
	sf::Vector2f m_position;

	float m_mass;
	float m_velocity { 0.0f };
	const float m_gravity { 9.80f };
	bool m_isGrounded { true };
	bool m_isIdle{ true };
	bool m_isWalking{ false };

	sf::Int32 m_timeAccumulation{ 0 };

	sf::Event m_event;

	enum class Direction
	{
		LEFT,
		RIGHT
	};

	Direction m_currentDir{ Direction::LEFT };
};



