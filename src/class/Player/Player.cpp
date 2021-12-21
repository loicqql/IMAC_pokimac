#include <string>
#include "Player.h"
#include "../../../libs/consoleUtils.hpp"

using namespace std;

Player::Player() {
  health = 100;
  x = 0;
  y = 0;
  exp = 50;
  damage = 30;
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

void Player::addHealth(int nbHealth) {
  health = health + nbHealth;
}

void Player::setHealth(int nbDamage) {
  health = health - nbDamage;
}

// Damage

int Player::getDamage() {
  return damage;
}

void Player::addDamage(int nbDamage) {
  damage = damage + nbDamage;
}

// Exp

int Player::getExp() {
  return exp;
}

void Player::addExp(int nbExp) {
  exp = exp + nbExp;
}

// Attack

int Player::attack(Pokimac *p_pokimac) {
  int nb = ((rand()%10)+1)*10;
  if(exp >= nb) {
    p_pokimac->setHealth(damage);
    return damage;
  }else {
    return 0;
  }
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