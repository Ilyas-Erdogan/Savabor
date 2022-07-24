#pragma once

#include "SFML/Graphics.hpp"
#include <string>
#include "Animation.h"

class Character
{
public:
	Character(const std::string textureName);
	~Character();

	virtual void processEvents(sf::Event event) = 0;
	virtual void update(sf::Int32 dt) = 0;
	virtual void render() = 0;

	virtual void play(sf::Int32 dt) = 0;
	virtual void pause() = 0;
	
	void setTextureRects(std::vector<sf::IntRect> textureRects);
	void setCurrentRect(sf::IntRect currentRect);

	sf::Texture getTexture();
	sf::Sprite getSprite();

protected:
	sf::Texture m_texture;
	std::vector<sf::IntRect> m_textureRects;
	sf::IntRect m_currentRect;
	sf::Sprite m_sprite;
	sf::Vector2f m_spriteScaleValues{ 4.f, 4.f };;
	sf::Vector2f m_position;
	sf::Int32 m_timeAccumulation{ 0 };
	sf::Event m_event;

	std::string m_textureName;
	int m_rectIndex{ 0 };
	float m_mass{ 50.f };
	float m_velocity{ 0.0f };
	const float m_gravity{ 9.80f };
	bool m_isGrounded{ true };
	bool m_isIdle{ true };
	bool m_isWalking{ false };
	bool m_isAttacking{ false };
	bool m_isPlaying{ true };
	bool m_isPaused{ false };
	bool m_isLooping{ false };
	enum class Direction{ LEFT, RIGHT };
	enum class AnimationType{ IDLE, MOVING_LEFT, MOVING_RIGHT, JUMP, ATTACK };
	
	Direction m_currentDirection{ Direction::LEFT };

	AnimationType m_currentAnimationType{ AnimationType::IDLE };
};

