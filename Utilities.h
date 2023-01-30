//
// Created by Stanislav Kramar on 1/30/23.
//

#ifndef SNAKE_GAME_UTILITIES_H
#define SNAKE_GAME_UTILITIES_H

#include <random>

#include "Singleton.h"

namespace snake_game {
    template<typename T>
    class Utilities : public Singleton<Utilities<T>> {
    private:
        friend class Singleton<Utilities<T>>;
    public:
        T getRandomInRange(T a, T b) {
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_real_distribution<T> dist(a, b);

            return dist(mt);
        }
    };
}


#endif //SNAKE_GAME_UTILITIES_H
