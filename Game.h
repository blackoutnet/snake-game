//
// Created by Stanislav Kramar on 1/30/23.
//

#ifndef SNAKE_GAME_GAME_H
#define SNAKE_GAME_GAME_H


#include <SFML/Graphics/RenderWindow.hpp>

#include "GameEngine.h"
#include "RenderingEngine.h"


namespace snake_game {
    class Game {
    private:
        sf::RenderWindow* window;
        RenderingEngine* renderer;
        GameEngine* gameEngine;
    public:
        Game();

        ~Game();

        void run();

        void restart();
    };
}


#endif //SNAKE_GAME_GAME_H
