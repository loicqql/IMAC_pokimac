#include "Game.h"
using namespace std;

Game::Game(Player *p_player) {
  player = p_player;
}

void Game::movePlayer(char dir) {

  // MOVE PLAYER

  int x, y;
  x = player->getX();
  y = player->getY();
  // cout << x << " " << y;
  ConsoleUtils::setCursorPos(x, y); std::cout << map.getDisplayByCoords(x, y);
  player->move(dir);
  x = player->getX();
  y = player->getY();
  ConsoleUtils::setCursorPos(x, y); std::cout << DISPLAY_PLAYER;

  //EVENTS
  switch (map.getValueByCoords(x, y)) {
  case POKIMAC:
    initPlayerAttack();
    break;
  case HIDDEN_POKIMAC:
    initPlayerAttack();
    break;
  
  default:
    break;
  }

}

void Game::initPlayerAttack() {
  ConsoleUtils::clear();
  ConsoleUtils::setCursorPos(0, 0);
  cout << "Ecran de combat";
}