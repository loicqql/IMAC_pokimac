#include <string>
#include <iostream>
#include "Map.h"
#include "../../../libs/consoleUtils.hpp"

using namespace std;

Map::Map() {
  
  for (int i = 0; i < tab_size; i++) {
    tab[i] = VOID;
  }

  tab[0] = GRASS;

  initDisplay();
  
}

void Map::initDisplay() {
  ConsoleUtils::clear();
  for (int i = 0; i < SIZE_MAP; i++) {
    for (int j = 0; j < SIZE_MAP; j++) {
      ConsoleUtils::setCursorPos(i,j); std::cout << getDisplayByCoords(i, j);
    }
  }
  ConsoleUtils::setCursorPos(0,0);
}

char Map::getDisplayByCoords(int x, int y) {
  int intTab = tab[y * SIZE_MAP + x];
  char charDisplay;
  switch (intTab) {
  case VOID:
    charDisplay = DISPLAY_VOID;
    break;
  case GRASS:
    charDisplay = DISPLAY_GRASS;
    break;
  case POKIMAC:
    charDisplay = DISPLAY_POKIMAC;
    break;
  default:
    charDisplay = DISPLAY_VOID;
    break;
  }

  return charDisplay;
}