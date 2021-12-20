#pragma once

#include "../Map/Map.h"
#include "../Player/Player.h"
#include "./Event/Event.h"

#define MAP_DISPLAYED 0
#define PLAYER_ATTACK_POKIMAC 1
#define POKIMAC_ATTACK_PLAYER 2

using namespace std;

class Game {
public:
  Game(Player *p_player);
  void movePlayer(char dir);
  void makeChoice(char choice);

private:
  Map map;
  Event event;
  Player *player;
  int game_mode;

  void PlayerAttackPokimac();
  void PokimacAttackPlayer();
  void displayMap();
};