#include "../include/game.hpp"
#include "../include/config.hpp"
#include "../include/entities.hpp"
// TODO: Make this code more readble
Game::Game() : window(config::SCREEN_W, config::SCREEN_H, "Snake Game") {
  window.SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  window.SetPosition(100, 100);
}
void Game::GameLoop(Player *snake, Fruit *apple) {
  while (!window.ShouldClose()) {
    float deltaTime = window.GetFrameTime();
    snake->moveSnake(&deltaTime);
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
    while (window.Drawing()) {
      UpdateDraw(snake, apple);
    }
  }
}
void Game::UpdateDraw(Player *snake, Fruit *apple) {
  window.ClearBackground(GRAY);
  snake->drawSnake();
  apple->drawFruit();
}
