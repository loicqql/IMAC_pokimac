#include "Game.h"
using namespace std;

Game::Game(Player *p_player) {
  player = p_player;
  game_mode = MAP_DISPLAYED;
}

void Game::movePlayer(char dir) {

  // MOVE PLAYER

  int x, y;
  x = player->getX();
  y = player->getY();

  if(game_mode == MAP_DISPLAYED) {
    // cout << x << " " << y;
    ConsoleUtils::setCursorPos(x, y); std::cout << map.getDisplayByCoords(x, y);
    player->move(dir);
    x = player->getX();
    y = player->getY();
    ConsoleUtils::setCursorPos(x, y); std::cout << DISPLAY_PLAYER;
  }
  

  //EVENTS
  switch (map.getValueByCoords(x, y)) {
  case POKIMAC:
    game_mode = FIGHT;
    pokimac = map.getPokimacByCoords(x, y);
    event.playerAttackPokimac(player, pokimac);
    break;
  case HIDDEN_POKIMAC:
    game_mode = FIGHT;
    event.playerAttackPokimac(player, pokimac);
    break;
  
  default:
    break;
  }

}

void Game::makeChoice(char choice) {
  if(game_mode != MAP_DISPLAYED) {
    if(game_mode == FIGHT) {
      switch (choice) {
      case 'w':
        combat(true);
        break;
      case 'x':
        combat(false);
        break;
      default: break;
      }
    }
  }
}

void Game::combat(bool isAttack) {
  if(isAttack) {
    // interaction avec le pokimac
    // verif si le pokimac a toujours de la vie
    event.addLog("Tu as perdu 12 pt de vie");
    event.playerAttackPokimac(player, pokimac);
    // sinon -> ecran de win
    
  }else {
    game_mode = MAP_DISPLAYED;
    displayMap();
  }
}

void Game::displayMap() {
  map.displayMap();
  event.clearLogs();
}