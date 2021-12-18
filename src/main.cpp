#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include "class/Player/Player.h"
#include "../libs/consoleUtils.hpp"
#include "class/Map/Map.h"

using namespace std;

int main() {
  Map map;
  Player poki(&map);

  // cout << poki.getHealth() << endl;
  // poki.setHealth(50); 

  // cout << poki.getHealth() << endl;

  int x = poki.getX();
  int y = poki.getY();
  bool exitLoop = false;

  while (!exitLoop) {

    if (ConsoleUtils::kbhit()) { //if a key is pressed
      bool special = false;
			int c = ConsoleUtils::getChar(&special); // Get character
      switch (c) {
        case 'z': poki.move('N'); break;
        case 's': poki.move('S'); break;
        case 'q': poki.move('W'); break;
        case 'd': poki.move('E'); break;
        case ' ': exitLoop = true; break;
        default: break;
      }
    }
  }

  ConsoleUtils::clear();

  return 0;
}