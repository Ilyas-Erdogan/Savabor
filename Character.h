#pragma once

#include "SFML/Graphics.hpp"
#include <string>
#include "Animation.h"

class Character
{
public:
	Character(const std::string textureName);
	~Character();

	void processEvents(sf::Event event);
	void update(sf::Time dt);
	void render();

	void setDirection();
	void setAnimation();
	void setRects();

	void animate(sf::Time dt, int animationRate);
	void play();
	void pause();

	virtual void action(sf::Time dt) = 0;
	void checkBounds();
	
	void setTextureRects(std::vector<sf::IntRect> textureRects);
	void setCurrentRect(sf::IntRect currentRect);
	virtual void setIdleRects() = 0;
	virtual void setWalkingRects() = 0;
	virtual void setJumpingRects() = 0;

	sf::Texture getTexture();
	sf::Sprite getSprite();

protected:
	sf::Texture m_texture;
	std::vector<sf::IntRect> m_textureRects;
	sf::IntRect m_currentRect;
	sf::Sprite m_sprite;
	sf::Vector2f m_spriteScaleValues{ 4.f, 4.f };
	sf::Vector2f m_position;
	sf::Int32 m_timeAccumulationAnimation{ 0 };
	float m_timeAccumulationAction{ 0 };
	int m_animationRate{ 0 };

	std::string m_textureName;
	int m_rectIndex{ 0 };

	const float m_mass{ 20.f };
	const float m_gravity{ 9.81f };
	sf::Vector2f m_acceleration{ 50.0f, 10.f };
	sf::Vector2f m_initialVelocity{ 500.f, 0.f };
	sf::Vector2f m_currentVelocity{ m_initialVelocity.x, m_initialVelocity.y };

	bool m_isGrounded{ true };
	bool m_isIdle{ true };
	bool m_isWalking{ false };
	bool m_isAttacking{ false };
	bool m_isJumping{ false };

	bool m_isPlaying{ true };
	bool m_isLooping{ false };
	enum class Direction{ LEFT, RIGHT };
	enum class AnimationType{ IDLE, MOVING, JUMPING, ATTACK };
	
	Direction m_currentDirection{ Direction::LEFT };

	AnimationType m_currentAnimationType{ AnimationType::IDLE };

	struct pressedKeys
	{
		bool key_a{ false };
		bool key_d{ false };
		bool key_w{ false };
	};

	pressedKeys m_pressedKeys;
};

