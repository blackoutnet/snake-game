//
// Created by Stanislav Kramar on 1/30/23.
//

#include "Settings.h"
#include "Snake.h"


using namespace snake_game;

Snake::Snake() {
    reset();
}

Snake::~Snake() = default;

void Snake::move(const sf::Vector2f& direction) {
    tail->setPosition(head->getPosition() + direction);
    head = tail;
    ++tail;

    if (tail == body.end()) {
        tail = body.begin();
    }
}

void Snake::grow(const sf::Vector2f& direction) {
    sf::Sprite newPart;
    newPart.setPosition(head->getPosition() + direction);
    head = body.insert(++head, newPart);
}

bool Snake::hasCollided(const sf::Sprite& other) const {
    return other.getGlobalBounds().intersects(head->getGlobalBounds());
}

bool Snake::hasIntersectedItself() const {
    bool hasIntersectedItself = false;

    for (auto piece = body.begin(); piece != body.end(); piece++) {
        if (head != piece) {
            hasIntersectedItself = hasCollided(*piece);
            break;
        }
    }

    return hasIntersectedItself;
}

void Snake::setInitialPosition() {
    float minDirectionChange = Settings::getInstance().getUnit();
    float x = minDirectionChange;
    for (auto& piece: body) {
        piece.setPosition({x, minDirectionChange});
        x += minDirectionChange;
    }
}

std::list<sf::Sprite>* Snake::getBody() {
    return &body;
}

void Snake::reset() {
    body = std::list<sf::Sprite>(Settings::getInstance().getSnakeStartSize());
    head = --body.end();
    tail = body.begin();

    setInitialPosition();
}
