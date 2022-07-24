#include "Animation.h"


Animation::Animation()
{

}

Animation::~Animation()
{

}

void Animation::setAnimationRects(std::vector<sf::IntRect>& animationRects)
{
	m_animationRects = &animationRects;
}

void Animation::setCurrentRect(sf::IntRect& currentRect)
{
	m_currentRect = &currentRect;
}

void Animation::play()
{
	m_isPlaying = true;
}

void Animation::pause()
{
	m_isPlaying = false;
}

void Animation::idle()
{
	setCurrentRect(m_animationRects->at(0));
}

void Animation::moveLeft()
{

}
void Animation::moveRight()
{

}
void Animation::jump()
{

}
void Animation::attack()
{

}

