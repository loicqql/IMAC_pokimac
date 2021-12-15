#include <string>
#include <iostream>
#include "Map.h"
#include "../../libs/consoleUtils.hpp"

using namespace std;

Map::Map() {
  for (int i = 0; i < tab_size; i++) {
    tab[i] = VOID;
  }
  
}