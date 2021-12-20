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
    game_mode = PLAYER_ATTACK_POKIMAC;
    event.playerAttackPokimac();
    break;
  case HIDDEN_POKIMAC:
    game_mode = PLAYER_ATTACK_POKIMAC;
    event.playerAttackPokimac();
    break;
  
  default:
    break;
  }

}

void Game::makeChoice(char choice) {
  if(game_mode != MAP_DISPLAYED) {
    if(game_mode == PLAYER_ATTACK_POKIMAC) {
      switch (choice) {
      case 'w':
        PlayerAttackPokimac();
        break;
      case 'x':
        displayMap();
        break;
      default: break;
      }
    }
    if(game_mode == POKIMAC_ATTACK_PLAYER) {
      switch (choice) {
      case 'w':
        PlayerAttackPokimac();
        break;
      case 'x':
        displayMap();
        break;
      default: break;
      }
    }
  }
}

void Game::PlayerAttackPokimac() {
  event.addLog("Tu as choisi d'attaquer Robibi");

  // interaction avec le pokimac
  // verif si le pokimac a toujours de la vie
  game_mode = POKIMAC_ATTACK_PLAYER;
  event.addLog("Tu as perdu 12 pt de vie");
  event.PokimacAttackPlayer();
  // sinon -> ecran de win
}

void Game::displayMap() {
  game_mode = PLAYER_ATTACK_POKIMAC;
  map.displayMap();
  event.clearLogs();
}