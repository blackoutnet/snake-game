//
// Created by Stanislav Kramar on 1/30/23.
//

#include "Settings.h"

using namespace snake_game;

float Settings::getUnit() const {
    return UNIT;
}

size_t Settings::getSnakeStartSize() const {
    return SNAKE_START_SIZE;
}

int Settings::getWindowWidth() const {
    return WINDOW_WIDTH;
}

int Settings::getWindowHeight() const {
    return WINDOW_HEIGHT;
}

std::string Settings::getWindowTitle() const {
    return WINDOW_TITLE;
}

float Settings::getFramesPerSecond() const {
    return FRAMES_PER_SECOND;
}

float Settings::getSecondsPerFrame() const {
    return 1.0f / getFramesPerSecond();
}

std::filesystem::path Settings::getTexturesDirectory() const {
    return TEXTURES_DIRECTORY;
}


std::filesystem::path Settings::getFontsDirectory() const {
    return FONTS_DIRECTORY;
}

float Settings::getSnakeSpeed() const {
    return SNAKE_SPEED;
}

int Settings::getFontSize() const {
    return FONT_SIZE;
}
