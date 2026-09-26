#include "../include/game.hpp"
#include "../include/config.hpp"
#include "../include/entities.hpp"
#include "raylib.h"
#include <string>

Game::Game() : window(config::SCREEN_W, config::SCREEN_H, "Snake Game") {
  window.SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  window.SetPosition(100, 100);
  window.SetTargetFPS(120);
}
void Game::GameLoop(Player *snake, Fruit *apple) {
    bool gameOver = false;

    while (!window.ShouldClose()) {
        float deltaTime = window.GetFrameTime();

        if (!gameOver) {
            inputHandiling(snake);
            snake->moveSnake(&deltaTime);
            apple->detectCollision(snake);

            if (snake->checkSelfCollision() || snake->checkWallCollision()) {
                gameOver = true;
            }
        } else {
            if (raylib::Keyboard::IsKeyPressed(KEY_R) || 
                raylib::Keyboard::IsKeyPressed(KEY_ENTER)) {
                snake->reset();
                apple->spawnFruitRandom();
                gameOver = false;
            }
        }

        while (window.Drawing()) {
            if (!gameOver) {
                UpdateDraw(snake, apple);
            } else {
                DrawGameOver(snake->getScore());
            }
        }
    }
}

void Game::DrawGameOver(int finalScore) {
    window.ClearBackground(BLACK);

    const char *title = "GAME OVER";
    int titleWidth = MeasureText(title, 40);
    DrawText(title, (config::SCREEN_W - titleWidth) / 2, config::SCREEN_H / 3, 40, RED);

    std::string scoreText = "Pontos: " + std::to_string(finalScore);
    int scoreWidth = MeasureText(scoreText.c_str(), 24);
    DrawText(scoreText.c_str(), (config::SCREEN_W - scoreWidth) / 2, config::SCREEN_H / 2, 24, RAYWHITE);

    const char *restart = "Pressione [R] para Reiniciar";
    int restartWidth = MeasureText(restart, 20);
    DrawText(restart, (config::SCREEN_W - restartWidth) / 2, config::SCREEN_H / 2 + 50, 20, LIGHTGRAY);
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
  window.ClearBackground(DARKBROWN);
  apple->drawFruit();
  snake->drawSnake();
}
