#include "../include/game.hpp"
int main() {
  Game game;
  Player snake;
  game.GameLoop(&snake);
  return 0;
}
