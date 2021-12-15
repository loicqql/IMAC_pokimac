#include <string>
#include "Player.h"

using namespace std;

Player::Player() {
  health = 100;
}

Player::Player(int nbHealth) {
  health = nbHealth;
}

// Name

string Player::getName() {
  return name;
}

void Player::setName(string username) {
  name = username;
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