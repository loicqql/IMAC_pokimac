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
    pokimac = map.getPokimacByCoords(x, y);
    if(!pokimac->isDefeated()) {
      game_mode = FIGHT;
      event.playerAttackPokimac(player, pokimac);
    }
    break;
  case HIDDEN_POKIMAC:
    pokimac = map.getPokimacByCoords(x, y);
    if(!pokimac->isDefeated()) {
      game_mode = FIGHT;
      event.playerAttackPokimac(player, pokimac);
    }
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
    if(game_mode == POKIMAC_DEFEATED) {
      switch (choice) {
      case 'a':
        game_mode = MAP_DISPLAYED;
        displayMap();
        break;
      default: break;
      }
    }
  }
}

void Game::combat(bool isAttack) {
  if(isAttack) {

    srand((unsigned)time(0)); //pour random dans player
    int damage = player->attack(pokimac);
    if(pokimac->getHealth() > 0) {
      // player attack pokimac
      event.addLog(damage == 0 ? "Tu n'as pas réussi à faire de dégâts" : "Tu as réussi à faire " + to_string(damage) + " points de dégâts à " + pokimac->getName());

      // pokimac attack player
      int nb = ((rand()%10)+1)*10;
      if(pokimac->getExp() >= nb) {
        event.addLog(pokimac->getName() + " n'a pas réussi à te faire de dégâts");
      }else {
        player->setHealth(pokimac->getDamage());
        event.addLog(pokimac->getName() + " t'a infligé " + to_string(pokimac->getDamage()) + " points de dégâts");
      }

      if(player->getHealth() <= 0) {
        game_mode = PLAYER_DEFEATED;
        event.playerDefeated();
      }else {
        // reset display
        event.playerAttackPokimac(player, pokimac);
      }
      
      
    }else {
      game_mode = POKIMAC_DEFEATED;
      pokimac->setDefeated(true);
      event.pokimacDefeated(pokimac);
    }
    
  }else {
    game_mode = MAP_DISPLAYED;
    displayMap();
  }
}

void Game::displayMap() {
  map.displayMap();
  event.clearLogs();
}