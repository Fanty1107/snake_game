#include "../include/game.hpp"
int main() {
  Game game;
  Player snake;
  Fruit apple;
  game.GameLoop(&snake, &apple);
  return 0;
}
