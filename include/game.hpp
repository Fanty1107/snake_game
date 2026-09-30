#pragma once
#include "../include/player.hpp"
#include "../include/fruit.hpp"

class Game {
private:
  raylib::Window window;

public:
  Game();
  void GameLoop(Player *snake, Fruit *apple);
  void inputHandiling(Player *snake);
  void UpdateDraw(Player *snake, Fruit *apple);
  void DrawGameOver(int finalScore);
};
