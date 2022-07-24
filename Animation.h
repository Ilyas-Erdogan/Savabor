#pragma once

#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation();
	~Animation();

	void setAnimationRects(std::vector<sf::IntRect>& animationRects);
	void setCurrentRect(sf::IntRect& currentRect);

	void play();
	void pause();

	void idle();
	void moveLeft();
	void moveRight();
	void jump();
	void attack();
private:
	int m_currentAnimation{ 0 };
	bool m_isPlaying{ true };
	bool m_isPaused{ false };

	std::vector<sf::IntRect>* m_animationRects{ nullptr };
	sf::IntRect* m_currentRect {nullptr};
};

