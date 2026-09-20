#pragma once
#include "entities.hpp"

class Game {
private:
  raylib::Window window;

public:
  Game();
  void GameLoop(Player *snake, Fruit *apple);
  void UpdateDraw(Player *snake, Fruit *apple);
};
