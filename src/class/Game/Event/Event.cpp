#include "Event.h"
using namespace std;

void Event::initEvent() {

  ConsoleUtils::clear();
  ConsoleUtils::setCursorPos(0, 0);
}

void Event::playerAttackPokimac(Player *p_player, Pokimac *p_pokimac) {
  initEvent();
  cout << "Tu as rencontré un pokimac !" << endl;
  cout << "Que souhaites-tu faire ?" << endl;

  cout << endl << "Tes stats :" << endl;
  cout << "Vie : " <<  p_player->getHealth() << endl;
  cout << "Points de dégâts : " <<  p_player->getDamage() << endl;
  cout << "Expérience : " <<  p_player->getExp() << "%" << endl;

  cout << endl << "w: Attaquer" << endl;
  cout << "x: Fuir";

  int transX = 40;
  ConsoleUtils::setCursorPos(transX, 3);
  cout << "Les stats de "  << p_pokimac->getName();
  ConsoleUtils::setCursorPos(transX, 4);
  cout << "Vie : " <<  p_pokimac->getHealth();
  ConsoleUtils::setCursorPos(transX, 5);
  cout << "Points de dégâts : " <<  p_pokimac->getDamage();
  ConsoleUtils::setCursorPos(transX, 6);
  cout << "Expérience : " <<  p_pokimac->getExp() << "%";

  displayLogs();
    
}

void Event::pokimacDefeated(Pokimac *p_pokimac) {
  initEvent();
  cout << "Tu as vaincu " + p_pokimac->getName() << endl;
  cout << endl << "a: Continuer" << endl;
}

void Event::playerDefeated() {
  initEvent();
  cout << "GAME OVER" << endl;
  cout << "Tu n'as plus de vie" << endl;
  cout << endl << "espace: quitter" << endl;
}

void Event::addLog(string text) {
  logs.push_back(text);
  displayLogs();
}

void Event::displayLogs() {
  ConsoleUtils::setCursorPos(0, 11);
  for(std::size_t i = 0; i < logs.size(); ++i){
    cout << logs[i] << endl;
  }
}

void Event::clearLogs() {
  logs.clear();
}