#include "Game.h"
#include "../Player/Inventory/Inventory.h"
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
      case 'c':
        if(Game::player->inventory->getNbItem(0)==0 && Game::player->inventory->getNbItem(1)==0){
          cout << "Inventaire vide !" << endl;
        }else{
          openInventory();
        }
        break;
      case 'v':
        openTeam();
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
    int damage = player->inventory->getTeam()[0].attack(pokimac);
    if(pokimac->getHealth() > 0) {
      // player attack pokimac
      event.addLog(damage == 0 ? "Tu n'as pas réussi à faire de dégâts" : "Tu as réussi à faire " + to_string(damage) + " points de dégâts à " + pokimac->getName());

      // pokimac attack player
      int nb = ((rand()%10)+1)*10;
      if(pokimac->getExp() >= nb) {
        event.addLog(pokimac->getName() + " n'a pas réussi à te faire de dégâts");
      }else {
        player->inventory->getTeam()[0].setHealth(pokimac->getDamage());
        event.addLog(pokimac->getName() + " t'a infligé " + to_string(pokimac->getDamage()) + " points de dégâts");
      }

      if(player->inventory->getTeam()[0].getHealth() <= 0) {
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

void Game::openInventory(){
  ConsoleUtils::clear();
  ConsoleUtils::setCursorPos(0, 0);
  Game::player->inventory->displayInventory();
  //choix objet inventaire
  bool exitLoop = false;
  while (!exitLoop) {
      if (ConsoleUtils::kbhit()) { //if a key is pressed
      bool special = false;
      int c = ConsoleUtils::getChar(&special); // Get character
        switch (c) {
            case 'x': //potion (soigne de 20)
                if(Game::player->inventory->getNbItem(0) > 0){
                    Game::player->inventory->rmItem(0);
                    player->inventory->getTeam()[0].addHealth(20);
                    exitLoop=true;
                }else{
                    cout << "Impossible, plus de potion de soin !"<<endl;
                }
                break;
            case 'c': //pokiball
                if(Game::player->inventory->getNbItem(1) > 0){
                    Game::player->inventory->rmItem(1);
                    catchPoki(pokimac);
                    //exitLoop=true;
                }else{
                    cout << "Impossible, plus de pokiball !"<<endl;
                }
                break;
              default:
                exitLoop = true;
                break;
        }
      } 
  }
  if(pokimac->isDefeated()){
    game_mode = MAP_DISPLAYED;
    displayMap();
  }else{
    event.playerAttackPokimac(player, pokimac);
  }
}

void Game::catchPoki(Pokimac *poki){
  if(Game::player->inventory->getTeamSize() < TEAM_CAPACITY){//cas team pas remplie
    if(
      ( (poki->getHealth()>50) && (rand()%100 < 50) ) //sous-cas pv poki > 50 : 50% de succès
      || ( (poki->getHealth()<=50) && (poki->getHealth()>20) && (rand()%100 < 75) ) //sous-cas 50 >= pv poki > 20 : 75% de succès
      || ( (poki->getHealth()<=20) && (rand()%100 < 90) )//sous-cas pv poki < 20 : 90% de succès
      ){
      Game::player->inventory->addPoki(poki);
      game_mode = POKIMAC_DEFEATED;
      event.pokimacCaught(poki);
    }else{//capture échouée
      event.addLog("Oh-oh, Poki s'est échappé de sa pokiball !");
      event.playerAttackPokimac(player, pokimac);
    }
  }else{//cas team remplie
    event.addLog("Impossible ! Equipe déjà au complet !");
  }
} 

void Game::openTeam(){
  ConsoleUtils::clear();
  ConsoleUtils::setCursorPos(0, 0);
  Game::player->inventory->showTeam();
  bool exitLoop=false;
  while (!exitLoop) {
    if (ConsoleUtils::kbhit()) { //if a key is pressed
      bool special = false;
      int c = ConsoleUtils::getChar(&special); // Get character
      switch (c) {
        default:
          exitLoop = true;
          event.playerAttackPokimac(player, pokimac);
          break;
      }
    }
  }
}