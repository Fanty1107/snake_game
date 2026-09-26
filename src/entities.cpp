#include "../include/entities.hpp"
#include "../include/config.hpp"

Player::Player() {
  body.push_back(raylib::Rectangle(100.0f, 100.0f, Snake::width, Snake::height));
}

void Player::drawSnake() { 
    for (size_t i = 0; i < body.size(); i++) {
        Color cor = (i == 0) ? DARKGREEN : GREEN;
        body[i].Draw(cor);
    } 
}

void Player::moveSnake(float *deltaTime) {
  static float moveTimer = 0.0f;
  const float moveInterval = 0.12f; 
  moveTimer += *deltaTime;

  if (moveTimer >= moveInterval) {

    moveTimer = 0.0f;
    lastMoveDirection = direction;
    raylib::Rectangle previousTail = body.back();

    for (size_t i = body.size() - 1; i > 0; i--) {
      body[i].x = body[i - 1].x;
      body[i].y = body[i - 1].y;
    }
    if (direction == SNAKE_DIRECTIONS::RIGHT) body[0].x += Snake::width;
    if (direction == SNAKE_DIRECTIONS::LEFT)  body[0].x -= Snake::width;
    if (direction == SNAKE_DIRECTIONS::DOWN)  body[0].y += Snake::height;
    if (direction == SNAKE_DIRECTIONS::UP)    body[0].y -= Snake::height;

    if (segmentsToAdd > 0) {
            body.push_back(previousTail);
            segmentsToAdd--;
    }
  }
}
void Player::changeDirection(SNAKE_DIRECTIONS next) {
  if (lastMoveDirection == SNAKE_DIRECTIONS::RIGHT && next == SNAKE_DIRECTIONS::LEFT) return;
  if (lastMoveDirection == SNAKE_DIRECTIONS::LEFT && next == SNAKE_DIRECTIONS::RIGHT) return;
  if (lastMoveDirection == SNAKE_DIRECTIONS::UP && next == SNAKE_DIRECTIONS::DOWN) return;
  if (lastMoveDirection == SNAKE_DIRECTIONS::DOWN && next == SNAKE_DIRECTIONS::UP) return;
  direction = next;
}

void Player::createSnakeBody(){
  segmentsToAdd++;
}
bool Player::checkSelfCollision() const {
    for (size_t i = 1; i < body.size(); i++) {
        if (body[0].CheckCollision(body[i])) {
            return true;
        }
    }
    return false;
}
bool Player::checkWallCollision() const {
    const raylib::Rectangle& head = body[0];
    if (head.x < 0.0f || head.y < 0.0f) {
        return true;
    }
    if (head.x + head.width > (float)config::SCREEN_W || 
        head.y + head.height > (float)config::SCREEN_H) {
        return true;
    }
    return false;
}

// -----------------------------------------------
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
