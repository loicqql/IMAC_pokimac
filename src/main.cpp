#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include "class/Player.h"
#include "../libs/consoleUtils.hpp"
#include "class/Map.h"

using namespace std;

int main() {
  Map map;
  Player poki(&map);

  cout << poki.getHealth() << endl;
  poki.setHealth(50); 

  cout << poki.getHealth() << endl;

  int x = 7;
  int y = 7;
  bool exitLoop = false;
  unsigned int cnt = 0;

  ConsoleUtils::setCursorPos(x,y); std::cout << 'P'; // first display
  while (!exitLoop) {
    
    ConsoleUtils::setCursorPos(8, 5); 
    std::cout << std::setfill('0') << std::setw(8) << cnt; // update cnt

    if (ConsoleUtils::kbhit()) { //if a key is pressed
      bool special = false;
			int c = ConsoleUtils::getChar(&special); // Get character

      ConsoleUtils::setCursorPos(18, 3); std::cout << (char)c << " - " << c << (special?" special Char":"             ");

      ConsoleUtils::setCursorPos(x, y); std::cout << ' '; // clean

      switch (c) {
        case 'z': poki.move('N'); break;
        case 's': poki.move('S'); break;
        case 'q': poki.move('W'); break;
        case 'd': poki.move('E'); break;
        case ' ': exitLoop = true; break;
        default: break;
      }
      ConsoleUtils::setCursorPos(x,y); std::cout << '@'; // display
    }
    ++cnt;
  }

  ConsoleUtils::clear();

  return 0;
}