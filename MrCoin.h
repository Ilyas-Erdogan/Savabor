#pragma once

#include "Animation.h"
#include <array>
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
	std::array<std::array<sf::IntRect, 3>,2> m_textureRects 
	{ {
		{ sf::IntRect(0, 0, 32, 32), sf::IntRect(32, 0, 32, 32), sf::IntRect(64, 0, 32, 32) },
		{ sf::IntRect(0, 32, 32, 32), sf::IntRect(32, 32, 32, 32), sf::IntRect(64, 32, 0, 0) }
	} };
	int m_sheetRow{ 0 };
	int m_sheetColumn{ 0 };
	std::array<sf::IntRect, 3>::iterator m_fItr{ m_textureRects[m_sheetRow].begin() };
	std::array<sf::IntRect, 3>::reverse_iterator m_rItr{ m_textureRects[m_sheetRow].rbegin() };
	bool m_forwardAnim{ true };
	bool m_reverseAnim{ false };
	sf::IntRect m_currentRect{m_textureRects[m_sheetRow][m_sheetColumn]};

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
};



