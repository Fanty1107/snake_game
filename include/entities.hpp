#pragma once
#include "Color.hpp"
#include "Rectangle.hpp"
#include "raylib-cpp.hpp"
#include <vector>

enum SNAKE_DIRECTIONS {
  RIGHT = 0,
  UP = 1,
  DOWN = -1,
  LEFT = 2,
};

namespace Snake {
constexpr float width = 50.0f;
constexpr float height = 50.0f;
constexpr raylib::Color color{GREEN};
constexpr float speed = 100.0f;
} // namespace Snake
namespace Apple {
constexpr float width = 20.0f;
constexpr float height = 20.0f;
constexpr raylib::Color color{RED};
} // namespace Apple
class Player {
private:
  std::vector<raylib::Rectangle> body;
  SNAKE_DIRECTIONS direction = SNAKE_DIRECTIONS::RIGHT; 
  SNAKE_DIRECTIONS lastMoveDirection = SNAKE_DIRECTIONS::RIGHT;
  int segmentsToAdd = 0;

public:
  Player();
  void drawSnake();
  void moveSnake(float *dT);
  void changeDirection(SNAKE_DIRECTIONS direction);
  void createSnakeBody();

  bool checkWallCollision() const;

  raylib::Rectangle getHead() const{
    return body.front();
  }
  bool checkSelfCollision() const;
};
class Fruit {
private:
  raylib::Rectangle fruit_shape;

public:
  Fruit();
  void drawFruit();
  void detectCollision(Player *snake);
  void spawnFruitRandom();
};
