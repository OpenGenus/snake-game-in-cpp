#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>

#include "Game.hpp"
#include "State.hpp"

class PauseGame : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_pauseTitle;

public:
    PauseGame(std::shared_ptr<Context> &context);
    ~PauseGame();

    void ProcessInput() override;
    void Init() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};