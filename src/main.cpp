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
  Map map();
  Player poki;

  cout << poki.getHealth() << endl;
  poki.setHealth(50); 

  cout << poki.getHealth() << endl;

  int x = 7;
  int y = 7;
  bool spaceHit = false;
  unsigned int cnt = 0;

  consoleUtils::setCursorPos(x,y); std::cout << '@'; // first display
  while (!spaceHit) {
    
    consoleUtils::setCursorPos(8, 5); 
    std::cout << std::setfill('0') << std::setw(8) << cnt; // update cnt

    if (consoleUtils::kbhit()) { //if a key is pressed
      const char c = consoleUtils::getChar(); // Get character
      consoleUtils::setCursorPos(x, y); std::cout << ' '; // clean
      switch (c) {
        case 'z': --y; break;
        case 's': ++y; break;
        case 'q': --x; break;
        case 'd': ++x; break;
        case ' ': spaceHit = true; break;
        default: break;
      }
      consoleUtils::setCursorPos(x,y); std::cout << '@'; // display
    }

    // Wanning: this sleep somehow breaks the console print
    consoleUtils::sleep(1);
    ++cnt;

  }

  consoleUtils::clear();

  return 0;
}