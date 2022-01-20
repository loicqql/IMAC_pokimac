#include <string>
#include <iostream>
#include "Map.h"
#include "../../../libs/consoleUtils.hpp"
#include "../Pokimac/Pokimac.h"
#include "Cell/Cell.h"

using namespace std;

Map::Map() {

  
  
  for (int i = 0; i < SIZE_MAP*SIZE_MAP; i++) {
    Cell *cell = new Cell;
    tab[i] = cell;
  }
  
  //ne pas changer l'ordre
  setupPokimacs();
  setupGrass();
  setupItems();
  displayMap();
  
}

void Map::displayMap() {
  ConsoleUtils::clear();
  for (int i = 0; i < SIZE_MAP; i++) {
    for (int j = 0; j < SIZE_MAP; j++) {
      ConsoleUtils::setCursorPos(i,j); std::cout << getDisplayByCoords(i, j);
    }
  }
}

int Map::getValueByCoords(int x, int y) {
  return tab[y * SIZE_MAP + x]->getValue();
}

void Map::setValueByCoords(int x, int y, int value) {
  return tab[y * SIZE_MAP + x]->setValue(value);
}

Pokimac * Map::getPokimacByCoords(int x, int y) {
  int index = tab[y * SIZE_MAP + x]->getPokimac();
  return pokis[index];
}

char Map::getDisplayByCoords(int x, int y) {
  char charDisplay;
  switch (tab[y * SIZE_MAP + x]->getValue()) {
  case VOID:
    charDisplay = DISPLAY_VOID;
    break;
  case GRASS:
    charDisplay = DISPLAY_GRASS;
    break;
  case HIDDEN_POKIMAC:
    if(getPokimacByCoords(x, y)->isDefeated()) {
      charDisplay = DISPLAY_GRASS;
    }else {
      charDisplay = DISPLAY_HIDDEN_POKIMAC;
    }
    break;
  case POKIMAC:
  if(getPokimacByCoords(x, y)->isDefeated()) {
      charDisplay = DISPLAY_VOID;
    }else {
      charDisplay = DISPLAY_POKIMAC;
    }
    break;
  case POTION:
      charDisplay = DISPLAY_POTION;
    break;
  case HIDDEN_POTION:
      charDisplay = DISPLAY_HIDDEN_POTION;
    break;
  case POKIBALL:
      charDisplay = DISPLAY_POKIBALL;
    break;
  case HIDDEN_POKIBALL:
      charDisplay = DISPLAY_HIDDEN_POKIBALL;
    break;
  default:
    charDisplay = DISPLAY_VOID;
    break;
  }

  return charDisplay;
}

void Map::setupPokimacs() {
  srand((unsigned)time(0)); // pour génération dans le constructeur des pokimac
  int coordsDuPoki;
  Pokimac *poki;
  for (int i = 0; i < NB_POKIS; i++) {
    poki = new Pokimac;
    poki->setName(names[i]);
    pokis[i] = poki;
    do {
      coordsDuPoki = ((rand()%(SIZE_MAP*SIZE_MAP))+1); // entre 0 et 400
    } while(tab[coordsDuPoki]->getValue() == POKIMAC);

    pokis[i]->setCoords(coordsDuPoki);
    pokis[i]->setDefeated(false);
    tab[coordsDuPoki]->setValue(POKIMAC);
    tab[coordsDuPoki]->setPokimac(i);
  }

}


void Map::setupGrass() {
  int tabGrass[] = {12,13,14,15,16,17,18,19,31,32,33,34,35,36,37,38,39,54,55,56,57,58,59};
  for (int i = 0; i < 23; i++) {
    tab[tabGrass[i]]->setValue(tab[i]->getValue() == POKIMAC ? HIDDEN_POKIMAC : GRASS);
  }

  int tabGrass2[] = {43,44,45,62,63,64,65,66,67,83,84,85,86};
  for (int i = 0; i < 13; i++) {
    tab[tabGrass2[i]]->setValue(tab[i]->getValue() == POKIMAC ? HIDDEN_POKIMAC : GRASS);
  }

  int tabGrass3[] = {130,131,132,133,134,135,149,150,151,152,153,154,155,156,157,168,169,170,171,172,173,174,175,191,192,193};
  for (int i = 0; i < 26; i++) {
    tab[tabGrass3[i]]->setValue(tab[i]->getValue() == POKIMAC ? HIDDEN_POKIMAC : GRASS);
  }

  int tabGrass4[] = {240,241,260,261,262,263,280,281,282,283,284,285,286,287,300,301,302,303,304,305,306,307,308,309,320,321,322,323,324,325,326,327,340,341,342,343,344,345};
  for (int i = 0; i < 38; i++) {
    tab[tabGrass4[i]]->setValue(tab[i]->getValue() == POKIMAC ? HIDDEN_POKIMAC : GRASS);
  }

  int tabGrass5[] = {399,398,397,396,379,378};
  for (int i = 0; i < 6; i++) {
    tab[tabGrass5[i]]->setValue(tab[i]->getValue() == POKIMAC ? HIDDEN_POKIMAC : GRASS);
  }
  
}

void Map::setupItems() {
  int coordsItems;
  int i;
  srand((unsigned)time(0));

  //POTIONS
  for ( i = 0; i < NB_POTIONS; i++) {
    do {
      coordsItems = ((rand()%(SIZE_MAP*SIZE_MAP))+1);
    } while(tab[coordsItems]->getValue() != VOID && tab[coordsItems]->getValue() != GRASS);

    if(tab[coordsItems]->getValue() == VOID) {
      tab[coordsItems]->setValue(POTION);
    }else {
      tab[coordsItems]->setValue(HIDDEN_POTION);
    }
  }

  if(tab[coordsItems]->getValue() == VOID) {
    tab[coordsItems]->setValue(POTION);
  }else {
    tab[coordsItems]->setValue(HIDDEN_POTION);
  }

  //POKIBALLS
  for (i = 0; i < NB_POKIBALLS; i++) {
    do {
      coordsItems = ((rand()%(SIZE_MAP*SIZE_MAP))+1);
    } while(tab[coordsItems]->getValue() != VOID && tab[coordsItems]->getValue() != GRASS);

    if(tab[coordsItems]->getValue() == VOID) {
      tab[coordsItems]->setValue(POKIBALL);
    }else {
      tab[coordsItems]->setValue(HIDDEN_POKIBALL);
    }
  }
  
}