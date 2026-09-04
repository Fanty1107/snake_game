#pragma once
#include "Color.hpp"
#include "raylib-cpp.hpp"

namespace Snake {
constexpr float width = 75.0f;
constexpr float height = 50.0f;
constexpr raylib::Color color{GREEN};
constexpr float speed = 500.0f;
} // namespace Snake
class Player {
private:
  raylib::Rectangle snake_shape;

public:
  Player();
  void drawSnake();
  void moveSnake(float dT);
};
