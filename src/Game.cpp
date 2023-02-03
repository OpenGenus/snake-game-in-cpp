#include "Game.hpp"
#include "MainMenu.hpp"

#include <SFML/Graphics/CircleShape.hpp>

Game::Game() : m_context(std::make_shared<Context>())
{
    m_context->m_window->create(sf::VideoMode(650, 352), "Classic Snake", sf::Style::Close);
    m_context->m_states->Add(std::make_unique<MainMenu>(m_context));
}

Game::~Game()
{
}

void Game::Run()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Clock clock;
    sf::Time timeSinceeLastFrame = sf::Time::Zero;

    while (m_context->m_window->isOpen())
    {
        timeSinceeLastFrame += clock.restart();

        while (timeSinceeLastFrame > TIME_PER_FRAME)
        {
            timeSinceeLastFrame -= TIME_PER_FRAME;

            m_context->m_states->ProcessStateChange();
            m_context->m_states->GetCurrent()->ProcessInput();
            m_context->m_states->GetCurrent()->Update(TIME_PER_FRAME);
            m_context->m_states->GetCurrent()->Draw();
        }
    }
}