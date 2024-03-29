#include "Game.h"
#include "Character.h"
#include "MrCoin.h"

MrCoin mrcoin;

Game::Game() : m_Window(sf::VideoMode(1200, 900), "Savabor", sf::Style::Close)
{
}

Game::~Game()
{
}

void Game::run()
{
	m_Window.setVerticalSyncEnabled(true);
	while (m_Window.isOpen())
	{
		dt = Clock.restart();
		processEvents();
		update(dt);
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_Window.close();
		}

		if (event.type == sf::Event::KeyPressed)
		{

			if (event.key.code == sf::Keyboard::Escape)
			{
				m_Window.close();
			}
		}
		mrcoin.processEvents(event);
	}

}

void Game::update(sf::Time dt)
{
	mrcoin.update(dt);
}

void Game::render()
{
	m_Window.clear(sf::Color::White);
	
	mrcoin.render();

	m_Window.draw(mrcoin.getSprite());

	m_Window.display();
}
