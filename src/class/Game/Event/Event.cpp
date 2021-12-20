#include "Event.h"
using namespace std;

void Event::initEvent() {

  ConsoleUtils::clear();
  ConsoleUtils::setCursorPos(0, 0);
}

void Event::playerAttackPokimac(Player *p_player, Pokimac *p_pokimac) {
  initEvent();
  cout << "Tu as rencontré un pokimac !" << endl;
  cout << "Que souhaites-tu faire ?";
  cout << endl << p_pokimac->getDamage();
  ConsoleUtils::setCursorPos(0, 3);
  cout << "w: Attaquer" << endl;
  cout << "x: Fuir";

  displayLogs();
    
}

void Event::addLog(string text) {
  logs.push_back(text);
  displayLogs();
}

void Event::displayLogs() {
  ConsoleUtils::setCursorPos(0, 6);
  for(std::size_t i = 0; i < logs.size(); ++i){
    cout << logs[i] << endl;
  }
}

void Event::clearLogs() {
  logs.clear();
}