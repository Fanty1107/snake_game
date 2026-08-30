#include "../include/game.hpp"
#include "../include/config.hpp"
#include "../include/entities.hpp"

Game::Game() : window(config::SCREEN_W, config::SCREEN_H, "teste") {}

void Game::GameLoop(Player *snake) {
  while (!window.ShouldClose()) {
    float deltaTime = window.GetFrameTime();
    while (window.Drawing()) {
      UpdateDraw(snake);
    }
  }
}
void Game::UpdateDraw(Player *snake) {
  window.ClearBackground(GRAY);
  snake->drawSnake();
}
