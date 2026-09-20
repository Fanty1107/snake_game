#include "../include/entities.hpp"
#include "../include/config.hpp"
#include "raylib.h"
// TODO: Inicialize all the entities and improve drawSnake()

Player::Player() : snake_shape(0.0f, 0.0f, Snake::width, Snake::height) {}

void Player::drawSnake() { snake_shape.Draw(Snake::color); }

void Player::moveSnake(float *deltaTime) {
  if (direction == SNAKE_DIRECTIONS::RIGHT) {
    snake_shape.x += Snake::speed * (*deltaTime);
  }
  if (direction == SNAKE_DIRECTIONS::LEFT) {
    snake_shape.x -= Snake::speed * (*deltaTime);
  }
  if (direction == SNAKE_DIRECTIONS::DOWN) {
    snake_shape.y += Snake::speed * (*deltaTime);
  }
  if (direction == SNAKE_DIRECTIONS::UP) {
    snake_shape.y -= Snake::speed * (*deltaTime);
  }
}
void Player::changeDirection(SNAKE_DIRECTIONS directionEnum) {
  direction = directionEnum;
}
// -----------------------------------------------
Fruit::Fruit()
    : fruit_shape((float)config::SCREEN_W / 2, (float)config::SCREEN_H / 2,
                  Apple::width, Apple::height) {}
void Fruit::drawFruit() { fruit_shape.Draw(Apple::color); }
