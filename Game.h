#pragma once

#include <SFML/graphics.hpp>
#include <iostream>

class Game
{
public:
    Game();
    ~Game();
    void run();

private:
    void processEvents();
    void update(sf::Time dt);
    void render();

private:
    sf::RenderWindow m_Window;
    sf::Clock Clock;
    sf::Time dt;
    
};
