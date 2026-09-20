#include "../include/game.hpp"
#include "../include/config.hpp"
#include "../include/entities.hpp"

Game::Game() : window(config::SCREEN_W, config::SCREEN_H, "Snake Game") {
  window.SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  window.SetPosition(100, 100);
}
void Game::GameLoop(Player *snake, Fruit *apple) {
  while (!window.ShouldClose()) {
    float deltaTime = window.GetFrameTime();
    snake->moveSnake(&deltaTime);
    inputHandiling(snake);
    apple->detectCollision(snake);
    while (window.Drawing()) {
      UpdateDraw(snake, apple);
    }
  }
}
void Game::inputHandiling(Player *snake) {
  if (raylib::Keyboard::IsKeyPressed(KEY_A) ||
      raylib::Keyboard::IsKeyPressed(KEY_LEFT)) {
    snake->changeDirection(SNAKE_DIRECTIONS::LEFT);
  }
  if (raylib::Keyboard::IsKeyPressed(KEY_W) ||
      raylib::Keyboard::IsKeyPressed(KEY_UP)) {
    snake->changeDirection(SNAKE_DIRECTIONS::UP);
  }
  if (raylib::Keyboard::IsKeyPressed(KEY_D) ||
      raylib::Keyboard::IsKeyPressed(KEY_RIGHT)) {
    snake->changeDirection(SNAKE_DIRECTIONS::RIGHT);
  }
  if (raylib::Keyboard::IsKeyPressed(KEY_S) ||
      raylib::Keyboard::IsKeyPressed(KEY_DOWN)) {
    snake->changeDirection(SNAKE_DIRECTIONS::DOWN);
  }
}
void Game::UpdateDraw(Player *snake, Fruit *apple) {
  window.ClearBackground(GRAY);
  apple->drawFruit();
  snake->drawSnake();
}
