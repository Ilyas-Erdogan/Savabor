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
	virtual void update(sf::Time dt) = 0;
	virtual void render() = 0;

	virtual void animate(sf::Time dt) = 0;
	void play();
	void pause();

	void setIdleVariables();
	void setWalkVariables();
	void setJumpVariables();
	virtual void action(sf::Time dt) = 0;
	void checkBounds();
	
	void setTextureRects(std::vector<sf::IntRect> textureRects);
	void setCurrentRect(sf::IntRect currentRect);

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

	std::string m_textureName;
	int m_rectIndex{ 0 };
	const float m_mass{ 20.f };
	const float m_gravity{ 9.81f };
	float m_acceleration{ 5.0f };
	float m_velocity{ 5.0f };
	bool m_isGrounded{ true };
	bool m_isIdle{ true };
	bool m_isWalking{ false };
	bool m_isAttacking{ false };
	bool m_isJumping{ false };
	bool m_isPlaying{ true };
	bool m_isLooping{ false };
	enum class Direction{ LEFT, RIGHT };
	enum class AnimationType{ IDLE, MOVING_LEFT, MOVING_RIGHT, JUMP, ATTACK };
	
	Direction m_currentDirection{ Direction::LEFT };

	AnimationType m_currentAnimationType{ AnimationType::IDLE };
};

