#include <string>
#include <iostream>
#include "Map.h"
#include "../../../libs/consoleUtils.hpp"

using namespace std;

Map::Map() {
  
  for (int i = 0; i < tab_size; i++) {
    tab[i] = VOID;
  }

  setupGrass();

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

void Map::setupGrass() {
  int tabGrass[] = {12,13,14,15,16,17,18,19,31,32,33,34,35,36,37,38,39,54,55,56,57,58,59};
  for (int i = 0; i < 23; i++) {
    tab[tabGrass[i]] = GRASS;
  }

  int tabGrass2[] = {43,44,45,62,63,64,65,66,67,83,84,85,86};
  for (int i = 0; i < 13; i++) {
    tab[tabGrass2[i]] = GRASS;
  }

  int tabGrass3[] = {130,131,132,133,134,135,149,150,151,152,153,154,155,156,157,168,169,170,171,172,173,174,175,191,192,193};
  for (int i = 0; i < 26; i++) {
    tab[tabGrass3[i]] = GRASS;
  }

  int tabGrass4[] = {240,241,260,261,262,263,280,281,282,283,284,285,286,287,300,301,302,303,304,305,306,307,308,309,320,321,322,323,324,325,326,327,340,341,342,343,344,345};
  for (int i = 0; i < 38; i++) {
    tab[tabGrass4[i]] = GRASS;
  }

  int tabGrass5[] = {400,399,398,397,396,379,378};
  for (int i = 0; i < 7; i++) {
    tab[tabGrass5[i]] = GRASS;
  }
  
}