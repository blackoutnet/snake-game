//
// Created by Stanislav Kramar on 1/30/23.
//

#include "GameEngine.h"
#include "Settings.h"
#include "Utilities.h"

using namespace snake_game;

GameEngine::GameEngine(sf::RenderWindow* window) :
        score(0),
        gameOver(false),
        window(window),
        timeSinceLastFrame(sf::Time::Zero),
        direction({16.0f, 0.0f}),
        border(std::array<sf::Sprite, 4>()),
        paused(false) {
    settings = &Settings::getInstance();
}

void GameEngine::handleInput() {
    sf::Event event = sf::Event();
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        } else if (event.type == sf::Event::KeyPressed) {
            sf::Vector2f newDirection = direction;
            float minDirectionChange = settings->getUnit();
            switch (event.key.code) {
                case sf::Keyboard::Up:
                    newDirection = {0.0f, -minDirectionChange};
                    break;
                case sf::Keyboard::Down:
                    newDirection = {0.0f, minDirectionChange};
                    break;
                case sf::Keyboard::Left:
                    newDirection = {-minDirectionChange, 0.0f};
                    break;
                case sf::Keyboard::Right:
                    newDirection = {minDirectionChange, 0.0f};
                    break;
                case sf::Keyboard::Escape:
                    paused = !paused;
                    break;

                default:
                    break;
            }

            if (std::abs(direction.x) != std::abs(newDirection.x) ||
                std::abs(direction.y) != std::abs(newDirection.y)) {
                direction = newDirection;
            }
        }
    }

}

void GameEngine::update() {
    float spf = settings->getSecondsPerFrame();
    timeSinceLastFrame += sf::seconds(spf);
    if (!paused && timeSinceLastFrame.asSeconds() > settings->getSnakeSpeed()) {
        Collision collision = checkCollision();
        switch (collision) {
            case Collision::BORDER:
                setGameOver(true);
                break;
            case Collision::FOOD:
                spawnFood();
                snake.grow(direction);
                setScore(score + 1);
                break;
            case Collision::SELF:
                setGameOver(true);
                break;
            case Collision::NO_COLLISION:
                snake.move(direction);
                break;
        }

        timeSinceLastFrame = sf::Time::Zero;
    }
}


Collision GameEngine::checkCollision() const {
    for (const auto& wall: border) {
        if (snake.hasCollided(wall)) {
            return Collision::BORDER;
        }
    }
    if (snake.hasCollided(food)) {
        return Collision::FOOD;
    }
    if (snake.hasIntersectedItself()) {
        return Collision::SELF;
    }

    return Collision::NO_COLLISION;
}

bool GameEngine::isGameOver() const {
    return gameOver;
}

int GameEngine::getScore() const {
    return score;
}


sf::Sprite* GameEngine::getField() {
    return &field;
}

std::array<sf::Sprite, 4>* GameEngine::getBorder() {
    return &border;
}


Snake* GameEngine::getSnake() {
    return &snake;
}


sf::Sprite* GameEngine::getFood() {
    return &food;
}

void GameEngine::setScore(int _score) {
    score = _score;
}


[[maybe_unused]] void GameEngine::setSnake(const Snake& _snake) {
    snake = _snake;
}

[[maybe_unused]] void GameEngine::setFood(const sf::Sprite& _food) {
    this->food = _food;
}

void GameEngine::setGameOver(bool isGameOver) {
    gameOver = isGameOver;
}

void GameEngine::spawnFood() {
    auto windowSize = window->getSize();
    auto& utils = Utilities<float>::getInstance();

    float x = utils.getRandomInRange(16, static_cast<float >(windowSize.x) - 2 * settings->getUnit());
    float y = utils.getRandomInRange(16, static_cast<float >(windowSize.y) - 2 * settings->getUnit());
    food.setPosition({x, y});
}

void GameEngine::setDirection(const sf::Vector2f& _direction) {
    direction = _direction;
}

void GameEngine::pause() {
    paused = true;
}


