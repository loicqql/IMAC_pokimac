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

void Cell::setPokimac(Pokimac *p_pokimac) {
  poki = p_pokimac;
}

Pokimac Cell::getPokimac() {
  return *poki;
}