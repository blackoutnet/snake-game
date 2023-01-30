//
// Created by Stanislav Kramar on 1/30/23.
//

#include "RenderingEngine.h"
#include "Settings.h"


using namespace snake_game;

RenderingEngine::RenderingEngine() : zeroFrame(true) {
    auto& settings = Settings::getInstance();
    auto texturesDirectory = settings.getTexturesDirectory();
    auto fontsDirectory = settings.getFontsDirectory();

    borderTexture = new sf::Texture();
    fieldTexture = new sf::Texture();
    snakeTexture = new sf::Texture();
    foodTexture = new sf::Texture();
    font = new sf::Font();


    borderTexture->loadFromFile(texturesDirectory / "border.png");
    borderTexture->setRepeated(true);

    fieldTexture->loadFromFile(texturesDirectory / "field.png");
    fieldTexture->setRepeated(true);

    snakeTexture->loadFromFile(texturesDirectory / "snake.png");
    foodTexture->loadFromFile(texturesDirectory / "food.png");

    font->loadFromFile(fontsDirectory / "font.ttf");

    scoreText.setFont(*font);
    scoreText.setCharacterSize(settings.getFontSize());
}

void RenderingEngine::render(GameEngine* game, sf::RenderWindow* window) {
    if (zeroFrame) {
        renderField(game, window);
        renderBorder(game, window);
        renderFood(game, window);
        zeroFrame = false;
    }
    renderSnake(game);
    updateScoreText(game);
}

void RenderingEngine::display(GameEngine* game, sf::RenderWindow* window) {
    window->clear(sf::Color::Blue);
    window->draw(*game->getField());

    for (auto& wall: *game->getBorder()) {
        window->draw(wall);

    }
    window->draw(*game->getFood());
    for (auto& piece: *game->getSnake()->getBody()) {
        window->draw(piece);
    }

    window->draw(scoreText);

    window->display();
}

void RenderingEngine::renderBorder(GameEngine* game, sf::RenderWindow* window) const {
    auto border = game->getBorder()->data();
    auto windowSize = window->getSize();
    auto sizeX = static_cast<int>(windowSize.x);
    auto sizeY = static_cast<int>(windowSize.y);

    for (int i = 0; i < 4; i++) {
        border[i].setTexture(*borderTexture);
    }

    border[0].setTextureRect({0, 0, sizeX, 16});
    border[1].setTextureRect({0, 0, sizeX, 16});
    border[1].setPosition(0, static_cast<float >(sizeY - 16));

    border[2].setTextureRect({0, 0, 16, sizeY});

    border[3].setTextureRect({0, 0, 16, sizeY});
    border[3].setPosition(static_cast<float >(sizeX - 16), 0);
}

void RenderingEngine::renderField(GameEngine* game, sf::RenderWindow* window) {
    auto field = game->getField();
    field->setTexture(*fieldTexture);

    field->setTextureRect(window->getViewport(window->getDefaultView()));
}

void RenderingEngine::renderSnake(GameEngine* game) {
    for (auto& piece: *game->getSnake()->getBody()) {
        if (piece.getTexture() == nullptr) {
            piece.setTexture(*snakeTexture);
        }
    }
}

void RenderingEngine::renderFood(GameEngine* game, sf::RenderWindow* window) {
    auto food = game->getFood();
    auto windowSize = window->getSize();
    food->setTexture(*foodTexture);
    food->setPosition(static_cast<float >(windowSize.x) / 2, static_cast<float >(windowSize.y) / 2);
}

void RenderingEngine::updateScoreText(GameEngine* game) {
    auto score = game->getScore();
    scoreText.setString("Score: " + std::to_string(score));
}

RenderingEngine::~RenderingEngine() {
    delete font;
    delete foodTexture;
    delete snakeTexture;
    delete fieldTexture;
    delete borderTexture;
}



