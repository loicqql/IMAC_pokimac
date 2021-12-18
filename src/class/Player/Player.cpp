#include <string>
#include "../Player/Player.h"
#include "../Pokimac/Pokimac.h"
#include "../Map/Map.h"
#include "../../../libs/consoleUtils.hpp"

using namespace std;

Player::Player(Map *p_map) {
  map = p_map;
  health = 100;
  x = 0;
  y = 0;
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
  clearCursor();
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
  setCursor();
}

void Player::clearCursor() {
  ConsoleUtils::setCursorPos(x, y); std::cout << map->getDisplayByCoords(x, y);
}

void Player::setCursor() {
  ConsoleUtils::setCursorPos(x, y); std::cout << 'P';
}