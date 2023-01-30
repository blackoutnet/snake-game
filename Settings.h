//
// Created by Stanislav Kramar on 1/30/23.
//

#ifndef SNAKE_GAME_SETTINGS_H
#define SNAKE_GAME_SETTINGS_H


#include <cstdlib>
#include <filesystem>
#include <string>

#include "Singleton.h"

namespace snake_game {
    class Settings : public Singleton<Settings> {
    public:
        [[nodiscard]] float getUnit() const;

        [[nodiscard]] size_t getSnakeStartSize() const;

        [[nodiscard]] float getSnakeSpeed() const;

        [[nodiscard]] int getWindowWidth() const;

        [[nodiscard]] int getWindowHeight() const;

        [[nodiscard]] std::string getWindowTitle() const;

        [[nodiscard]] float getFramesPerSecond() const;

        [[nodiscard]] float getSecondsPerFrame() const;

        [[nodiscard]] std::filesystem::path getTexturesDirectory() const;

        [[nodiscard]] std::filesystem::path getFontsDirectory() const;

        [[nodiscard]] int getFontSize() const;


    private:
        friend class Singleton<Settings>;
        const float UNIT = 16.0f;
        const size_t SNAKE_START_SIZE = 4;
        const float SNAKE_SPEED = 1.0 / 30.0;
        const int WINDOW_WIDTH = 1920;
        const int WINDOW_HEIGHT = 1080;
        const std::string WINDOW_TITLE = "Snake Game";
        const float FRAMES_PER_SECOND = 60.0f;
        const std::filesystem::path ASSETS_DIRECTORY = "assets";
        const std::filesystem::path TEXTURES_DIRECTORY = ASSETS_DIRECTORY / "textures";
        const std::filesystem::path FONTS_DIRECTORY = ASSETS_DIRECTORY / "fonts";
        const int FONT_SIZE = 50;
    };
}


#endif //SNAKE_GAME_SETTINGS_H
