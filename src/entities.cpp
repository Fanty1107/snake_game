#include "../include/entities.hpp"

Player::Player() : snake_shape(0.0f, 0.0f, Snake::width, Snake::height) {}
void Player::drawSnake() { snake_shape.Draw(Snake::color); }

void Player::moveSnake(float deltaTime) {
  if (raylib::Keyboard::IsKeyDown(KEY_D)) {
    snake_shape.x += Snake::speed * deltaTime;
  }
}
