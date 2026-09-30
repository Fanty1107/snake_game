#include "../include/fruit.hpp"
#include "../include/config.hpp"

Fruit::Fruit()
    : fruit_shape((float)config::SCREEN_W / 2, (float)config::SCREEN_H / 2,
                  Apple::width, Apple::height) {}
void Fruit::spawnFruitRandom(){
  int cols = config::SCREEN_W / (int)Apple::width;
  int rows = config::SCREEN_H / (int)Apple::height;
  fruit_shape.x = (float)(GetRandomValue(1, cols - 2) * Apple::width);
  fruit_shape.y = (float)(GetRandomValue(1, rows - 2) * Apple::height);
}

void Fruit::drawFruit() { fruit_shape.Draw(Apple::color); }

void Fruit::detectCollision(Player *snake) {
  if (fruit_shape.CheckCollision(snake->getHead())) {
    snake->createSnakeBody();
    spawnFruitRandom();
  }
}

