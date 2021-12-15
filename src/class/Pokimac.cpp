#include <string>
#include "Pokimac.h"

using namespace std;

Pokimac::Pokimac() {
  health = 100;
}

Pokimac::Pokimac(int nbHealth) {
  health = nbHealth;
}

// Name

string Pokimac::getName() {
  return name;
}

void Pokimac::setName(string username) {
  name = username;
}

// Health

int Pokimac::getHealth() {
  return health;
}

void Pokimac::setHealth(int nbHealth) {
  health = health + nbHealth;
}

// Damage

int Pokimac::getDamage() {
  return damage;
}

void Pokimac::setDamage(int nbDamage) {
  health = health - nbDamage;
}