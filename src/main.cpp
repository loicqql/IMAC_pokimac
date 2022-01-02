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
#include "class/Player/Inventory/Inventory.h"

using namespace std;

int main() {
  Inventory inventory;
  Player player(&inventory);
  Game game(&player);
  
  

  int x = player.getX();
  int y = player.getY();
  
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