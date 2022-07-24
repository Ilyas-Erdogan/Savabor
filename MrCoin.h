#include "Character.h"
#pragma once

class MrCoin : public Character
{
public:
	MrCoin();
	~MrCoin();

	virtual void processEvents(sf::Event event) override;
	virtual void update(sf::Int32 dt) override;
	virtual void render() override;

	virtual void play(sf::Int32 dt) override;
	virtual void pause() override;

private:
	std::vector<sf::IntRect> m_idleLeft{ { sf::IntRect(0, 0, 32, 32), sf::IntRect(32, 0, 32, 32), sf::IntRect(64, 0, 32, 32), sf::IntRect(96, 0, 32, 32)} };
	std::vector<sf::IntRect> m_idleRight{ { sf::IntRect(128, 0, 32, 32), sf::IntRect(160, 0, 32, 32), sf::IntRect(192, 0, 32, 32), sf::IntRect(224, 0, 32, 32)} };
	std::vector<sf::IntRect> m_walkingLeft{ { sf::IntRect(0, 32, 32, 32), sf::IntRect(32, 32, 32, 32), sf::IntRect(64, 32, 32, 32) } };
	std::vector<sf::IntRect> m_walkingRight{ { sf::IntRect(128, 32, 32, 32), sf::IntRect(160, 32, 32, 32), sf::IntRect(192, 32, 32, 32) } };
};
