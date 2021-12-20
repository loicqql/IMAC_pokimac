#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include "../libs/consoleUtils.hpp"
#include "class/Player/Player.h"
#include "class/Map/Map.h"
#include "class/Game/Game.h"

using namespace std;

int main() {
  Player poki;
  Game game(&poki);
  

  int x = poki.getX();
  int y = poki.getY();
  
  bool exitLoop = false;

  while (!exitLoop) {
    ConsoleUtils::setCursorPos(SIZE_MAP + 1, SIZE_MAP + 1);
    if (ConsoleUtils::kbhit()) { //if a key is pressed
      bool special = false;
			int c = ConsoleUtils::getChar(&special); // Get character
      switch (c) {
        case 'z': game.movePlayer('N'); break;
        case 's': game.movePlayer('S'); break;
        case 'q': game.movePlayer('W'); break;
        case 'd': game.movePlayer('E'); break;
        case ' ': exitLoop = true; break;
        default: game.makeChoice(c); break;
      }
    }
  }

  ConsoleUtils::clear();

  return 0;
}