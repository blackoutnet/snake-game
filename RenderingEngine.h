//
// Created by Stanislav Kramar on 1/30/23.
//



#ifndef SNAKE_GAME_RENDERINGENGINE_H
#define SNAKE_GAME_RENDERINGENGINE_H

#include <SFML/Graphics.hpp>

#include "GameEngine.h"

namespace snake_game {

    class RenderingEngine {
    public:
        RenderingEngine();
        ~RenderingEngine();

        void render(GameEngine* game, sf::RenderWindow* window);

        void display(GameEngine* game, sf::RenderWindow* window);

    private:
        sf::Texture* borderTexture;
        sf::Texture* fieldTexture;
        sf::Texture* snakeTexture;
        sf::Texture* foodTexture;
        sf::Font* font;
        sf::Text scoreText;

        bool zeroFrame;

        void renderBorder(GameEngine* game, sf::RenderWindow* window) const;

        void renderField(GameEngine* game, sf::RenderWindow* window);

        void renderSnake(GameEngine* engine);

        void renderFood(GameEngine* engine, sf::RenderWindow* window);

        void updateScoreText(GameEngine* engine);
    };
}


#endif //SNAKE_GAME_RENDERINGENGINE_H
