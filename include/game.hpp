#pragma once
#include "entities.hpp"

class Game {
private:
  raylib::Window window;

public:
  Game();
  void GameLoop(Player *snake);
  void UpdateDraw(Player *snake);
};
