#pragma once
#include "Color.hpp"
#include "raylib-cpp.hpp"

enum SNAKE_DIRECTIONS {
  RIGHT = 0,
  UP = 1,
  DOWN = -1,
  LEFT = 2,
};

namespace Snake {
constexpr float width = 75.0f;
constexpr float height = 50.0f;
constexpr raylib::Color color{GREEN};
constexpr float speed = 500.0f;
} // namespace Snake
class Player {
private:
  raylib::Rectangle snake_shape;
  int direction = 0;

public:
  Player();
  void drawSnake();
  void moveSnake(float *dT);
  void changeDirection(SNAKE_DIRECTIONS direction);
};
