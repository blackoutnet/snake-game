//
// Created by Stanislav Kramar on 1/30/23.
//

#ifndef SNAKE_GAME_SINGLETON_H
#define SNAKE_GAME_SINGLETON_H


template <typename T>
class Singleton
{
public:
    static T& getInstance()
    {
        static T instance;
        return instance;
    }
protected:
    Singleton() = default;
    ~Singleton() = default;
public:
    Singleton(Singleton const &) = delete;
    Singleton& operator=(Singleton const &) = delete;
};


#endif //SNAKE_GAME_SINGLETON_H
