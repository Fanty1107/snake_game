#pragma once
#include "Color.hpp"
#include "Rectangle.hpp"
#include "raylib-cpp.hpp"
// TODO: Implementar colisões
// NOTE: e uma nova entidade,seria a maça que a cobra comeria para crescer,
// cada parte nova da cobra vai ser um Rectangle igual o corpo principal

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
namespace Apple {
constexpr float width = 20.0f;
constexpr float height = 35.0f;
constexpr raylib::Color color{RED};
} // namespace Apple
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
class Fruit {
private:
  raylib::Rectangle fruit_shape;

public:
  Fruit();
  void drawFruit();
};
