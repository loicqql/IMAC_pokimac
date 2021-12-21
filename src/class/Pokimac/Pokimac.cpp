#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Pokimac.h"
#include "../Map/Map.h"

using namespace std;

Pokimac::Pokimac() {
  health = ((rand()%10)+1)*10;
  damage = ((rand()%10)+1)*10;
  exp = ((rand()%6)+5)*10;
  name = "Poki";
}

// Name

string Pokimac::getName() {
  return name;
}

void Pokimac::setName(string username) {
  name = username;
}

//Coords 

int Pokimac::getX() {
  return x;
}

int Pokimac::getY() {
  return y;
}

void Pokimac::setCoords(int coords) {
  x = coords % SIZE_MAP;
  y = coords / SIZE_MAP;
}

// Health

int Pokimac::getHealth() {
  return health;
}

void Pokimac::setHealth(int nbDamage) {
  health = health - nbDamage;
}

// Damage

int Pokimac::getDamage() {
  return damage;
}

void Pokimac::addDamage(int nbDamage) {
  damage = damage + nbDamage;
}

// Exp

int Pokimac::getExp() {
  return exp;
}