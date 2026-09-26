#include "../include/entities.hpp"
#include "../include/config.hpp"
#include "Rectangle.hpp"
#include "raylib.h"

Player::Player() {
  body.push_back(raylib::Rectangle(100.0f, 100.0f, Snake::width, Snake::height));
}

void Player::drawSnake() { 
    for (size_t i = 0; i < body.size(); i++) {
        Color cor = (i == 0) ? DARKGREEN : GREEN;
        body[i].Draw(cor);
    } 
}

void Player::moveSnake(float *deltaTime) {
  for (size_t i = body.size() - 1; i > 0; i--) {
        body[i].x = body[i - 1].x;
        body[i].y = body[i - 1].y;
    }

    float step = Snake::speed * (*deltaTime);
    
    if (direction == SNAKE_DIRECTIONS::RIGHT) body[0].x += step;
    if (direction == SNAKE_DIRECTIONS::LEFT)  body[0].x -= step;
    if (direction == SNAKE_DIRECTIONS::DOWN)  body[0].y += step;
    if (direction == SNAKE_DIRECTIONS::UP)    body[0].y -= step;

}
void Player::changeDirection(SNAKE_DIRECTIONS directionEnum) {
  if (direction == SNAKE_DIRECTIONS::RIGHT && directionEnum == SNAKE_DIRECTIONS::LEFT) return;
  if (direction == SNAKE_DIRECTIONS::LEFT && directionEnum == SNAKE_DIRECTIONS::RIGHT) return;
  if (direction == SNAKE_DIRECTIONS::UP && directionEnum == SNAKE_DIRECTIONS::DOWN) return;
  if (direction == SNAKE_DIRECTIONS::DOWN && directionEnum == SNAKE_DIRECTIONS::UP) return;
  direction = directionEnum;
}

void Player::createSnakeBody(){
  raylib::Rectangle tail = body.back();
  body.push_back(tail);
}
bool Player::checkSelfCollision() const {
    for (size_t i = 1; i < body.size(); i++) {
        if (body[0].CheckCollision(body[i])) {
            return true;
        }
    }
    return false;
}

// -----------------------------------------------
Fruit::Fruit()
    : fruit_shape((float)config::SCREEN_W / 2, (float)config::SCREEN_H / 2,
                  Apple::width, Apple::height) {}
void Fruit::spawnFruitRandom(){
  fruit_shape.x = GetRandomValue(100, 1000);
  fruit_shape.y = GetRandomValue(50,  500);
}

void Fruit::drawFruit() { fruit_shape.Draw(Apple::color); }

void Fruit::detectCollision(Player *snake) {
  if (fruit_shape.CheckCollision(snake->getHead())) {
    snake->createSnakeBody();
    spawnFruitRandom();
  }
}
