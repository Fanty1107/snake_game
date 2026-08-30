#include "../include/entities.hpp"

Player::Player()
    : snake_pos(0.0f, 0.0f), snake_size(100.0f, 100.0f),
      snake_shape(snake_pos, snake_size) {}
void Player::drawSnake() { snake_shape.Draw(Snake::color); }
