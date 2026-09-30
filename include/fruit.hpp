#pragma once
#include "../include/player.hpp"

namespace Apple {
constexpr float width = 20.0f;
constexpr float height = 20.0f;
constexpr raylib::Color color{RED};
} // namespace Apple

class Fruit {
private:
  raylib::Rectangle fruit_shape;

public:
  Fruit();
  void drawFruit();
  void detectCollision(Player *snake);
  void spawnFruitRandom();
};

