#include <string>
#include "Player.h"
#include "../../../libs/consoleUtils.hpp"

using namespace std;

Player::Player(Inventory *p_inventory) {
  x = 0;
  y = 0;
  exp = 50;
  inventory = p_inventory;
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

// Exp

int Player::getExp() {
  return exp;
}

void Player::addExp(int nbExp) {
  exp = exp + nbExp;
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