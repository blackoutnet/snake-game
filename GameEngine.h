//
// Created by Stanislav Kramar on 1/30/23.
//

#ifndef SNAKE_GAME_GAMEENGINE_H
#define SNAKE_GAME_GAMEENGINE_H


#include <array>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Settings.h"
#include "Snake.h"

namespace snake_game {

    enum class Collision {
        BORDER,
        FOOD,
        SELF,
        NO_COLLISION
    };

    class GameEngine {
    public:
        explicit GameEngine(sf::RenderWindow* window);

        void handleInput();

        void update();

        Collision checkCollision() const;

        bool isGameOver() const;

        //getters
        int getScore() const;

        Snake* getSnake();

        sf::Sprite* getFood();

        std::array<sf::Sprite, 4>* getBorder();

        sf::Sprite* getField();

        //setters
        void setScore(int score);

        [[maybe_unused]] void setSnake(const Snake& snake);

        [[maybe_unused]] void setFood(const sf::Sprite& food);

        void setDirection(const sf::Vector2f& direction);

        void setGameOver(bool isGameOver);

        void pause();

    private:
        // game state
        int score;

        std::array<sf::Sprite, 4> border;
        sf::Sprite field;

        Snake snake;
        sf::Sprite food;
        sf::Vector2f direction;

        sf::Time timeSinceLastFrame;

        bool gameOver;
        bool paused;

        sf::RenderWindow* window;
        Settings* settings;

        void spawnFood();
    };
}


#endif //SNAKE_GAME_GAMEENGINE_H
