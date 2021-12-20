#include "Event.h"
using namespace std;

void Event::initEvent() {

  ConsoleUtils::clear();
  ConsoleUtils::setCursorPos(0, 0);
}

void Event::playerAttackPokimac() {
  initEvent();
  cout << "Tu as rencontré un pokimac !" << endl;
  cout << "Que souhaites-tu faire ?";
  ConsoleUtils::setCursorPos(0, 3);
  cout << "w: Attaquer" << endl;
  cout << "x: Fuir";

  ConsoleUtils::setCursorPos(0, 6);
  for(std::size_t i = 0; i < logs.size(); ++i){
    cout << logs[i] << endl;
  }
    
}

void Event::PokimacAttackPlayer() {
  initEvent();
  cout << "Un pokimac t'a attaqué !" << endl;
  cout << "Que souhaites-tu faire ?";
  ConsoleUtils::setCursorPos(0, 3);
  cout << "w: Attaquer" << endl;
  cout << "x: Fuir";

  ConsoleUtils::setCursorPos(0, 6);
  for(std::size_t i = 0; i < logs.size(); ++i){
    cout << logs[i] << endl;
  }
    
}

void Event::addLog(string text) {
  logs.push_back(text);
}

void Event::clearLogs() {
  logs.clear();
}