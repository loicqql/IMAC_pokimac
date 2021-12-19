#include <string>
#include "../Player/Player.h"
#include "../Pokimac/Pokimac.h"
#include "../../../libs/consoleUtils.hpp"
#include "../Map/Map.h"

using namespace std;

Player::Player() {
  health = 100;
  x = 0;
  y = 0;
  exp = 5;
}

// Name

string Player::getName() {
  return name;
}

void Player::setName(string username) {
  name = username;
}

//Coords 

int Player::getX() {
  return x;
}

int Player::getY() {
  return y;
}

// Health

int Player::getHealth() {
  return health;
}

void Player::setHealth(int nbHealth) {
  health = health + nbHealth;
}

// Damage

void Player::setDamage(int nbDamage) {
  health = health - nbDamage;
}

// Attack

void Player::attack(Pokimac &pokimac) {
  pokimac.setDamage(30);
}

// Map

void Player::move(char dir) {
  switch (dir) {
  case 'N':
    if(y > 0) {
      y--;
    }
    break;
  case 'E':
    if(x < SIZE_MAP - 1) {
      x++;
    }
    break;
  case 'S':
    if(y < SIZE_MAP - 1) {
      y++;
    }
    break;
  case 'W':
    if(x > 0) {
      x--;
    }
    break;
  
  default:
    break;
  }
}