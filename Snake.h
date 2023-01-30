//
// Created by Stanislav Kramar on 1/30/23.
//

#ifndef SNAKE_GAME_SNAKE_H
#define SNAKE_GAME_SNAKE_H

#include <list>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>


namespace snake_game {
    class Snake {
    public:
        Snake();

        ~Snake();

        void move(const sf::Vector2f& direction);

        void grow(const sf::Vector2f& direction);

        [[nodiscard]] bool hasCollided(const sf::Sprite& other) const;

        [[nodiscard]] bool hasIntersectedItself() const;

        std::list<sf::Sprite>* getBody();

        void reset();

    private:
        std::list<sf::Sprite> body;
        std::list<sf::Sprite>::iterator head;
        std::list<sf::Sprite>::iterator tail;

        void setInitialPosition();
    };
}


#endif //SNAKE_GAME_SNAKE_H
