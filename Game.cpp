//
// Created by Stanislav Kramar on 1/30/23.
//

#include "Game.h"
#include "Settings.h"


using namespace snake_game;

Game::Game() {
    auto& settings = Settings::getInstance();
    window = new sf::RenderWindow();
    window->create(
            sf::VideoMode(
                    settings.getWindowWidth(),
                    settings.getWindowHeight()
            ),
            settings.getWindowTitle(),
            sf::Style::Default,
            sf::ContextSettings()
    );

    gameEngine = new GameEngine(window);
    renderer = new RenderingEngine();
}

Game::~Game() {
    delete renderer;
    delete gameEngine;
    delete window;
}

void Game::run() {
    auto& settings = Settings::getInstance();

    sf::Clock clock;
    auto timeSinceLastFrame = sf::Time::Zero;

    while (window->isOpen()) {
        timeSinceLastFrame += clock.restart();
        auto spf = sf::seconds(settings.getSecondsPerFrame());

        while (timeSinceLastFrame > spf) {
            timeSinceLastFrame -= spf;
            gameEngine->handleInput();
            gameEngine->update();
            if (gameEngine->isGameOver()) {
                restart();
            }
            renderer->render(gameEngine, window);
            renderer->display(gameEngine, window);

        }
    }
}


void Game::restart() {
    auto windowSize = window->getSize();
    gameEngine->pause();
    gameEngine->getSnake()->reset();
    gameEngine->setScore(0);
    gameEngine->setDirection({Settings::getInstance().getUnit(), 0.0f});
    gameEngine->getFood()->setPosition({static_cast<float >(windowSize.x) / 2, static_cast<float >(windowSize.y) / 2});
    gameEngine->setGameOver(false);
}


