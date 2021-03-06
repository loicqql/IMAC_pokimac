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

  cout << endl << "Les stats de ton " << p_player->inventory->getTeam()[0].getName() << " : " << endl;
  cout << "Vie : " <<  p_player->inventory->getTeam()[0].getHealth() << endl;
  cout << "Points de dégâts : " <<  p_player->inventory->getTeam()[0].getDamage() << endl;
  cout << "Expérience : " <<  p_player->inventory->getTeam()[0].getExp() << "%" << endl;

  cout << endl << "w: Attaquer" << endl;
  cout << "x: Fuir" << endl;
  cout << "c: Inventaire" << endl;
  cout << "v: Équipe";

  int transX = 40;
  ConsoleUtils::setCursorPos(transX, 3);
  cout << "Les stats de "  << p_pokimac->getName() << " adverse";
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
  cout << "Tu as vaincu " + p_pokimac->getName() << " (+20 exp pour ton pokimac)" << endl;
  cout << endl << "a: Continuer" << endl;
}

void Event::playerDefeated() {
  initEvent();
  cout << "GAME OVER" << endl;
  cout << "Ton dernier pokimac n'a plus de vie" << endl;
  cout << endl << "espace: quitter" << endl;
}

void Event::displayMessage(string text) {
  initEvent();
  cout << text;
  cout << endl << "a: Continuer" << endl;
}

void Event::pokimacCaught(Pokimac *p_pokimac){
  initEvent();
  addLog("Bravo ! " + p_pokimac->getName() + " est capturé !\na: Continuer");
}

void Event::displayInventory(Player *p_player){
  cout << endl << "Inventaire :" << endl;
  cout << "x: Utiliser potion : reste " <<  p_player->inventory->getNbItem(0) << " (+20 PV) " <<  endl;
  cout << "c: Utiliser pokiball : reste " <<  p_player->inventory->getNbItem(1) << endl;
  cout << "espace: Revenir au combat" << endl;
  cout << endl << "";
}

void Event::addLog(string text) {
  logs.push_back(text);
  displayLogs();
}

void Event::displayLogs() {
  ConsoleUtils::setCursorPos(0, 15);
  for(std::size_t i = 0; i < logs.size(); ++i){
    cout << logs[i] << endl;
  }
}

void Event::clearLogs() {
  logs.clear();
}