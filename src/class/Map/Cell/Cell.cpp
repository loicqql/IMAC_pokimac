#include "Cell.h"
#include "../Map.h"

using namespace std;

Cell::Cell() {
  value = VOID;
}

int Cell::getValue() {
  return value;
}

void Cell::setValue(int new_value) {
  value = new_value;
}

void Cell::setPokimac(int index) {
  indexPoki = index;
}

int Cell::getPokimac() {
  return indexPoki;
}