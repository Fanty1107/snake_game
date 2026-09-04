#include "../include/entities.hpp"

Player::Player()
    : snake_pos(0.0f, 0.0f), snake_size(Snake::width, Snake::height),
      snake_shape(snake_pos, snake_size) {}
void Player::drawSnake() { snake_shape.Draw(Snake::color); }

void Player::moveSnake(float deltaTime) {
  if (raylib::Keyboard::IsKeyDown(KEY_D)) {
    snake_pos.x += Snake::speed * deltaTime;
    snake_shape.x = snake_pos.x;
  }
  snake_shape.y = snake_pos.y;
}
