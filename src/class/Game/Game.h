#pragma once

#include "../Map/Map.h"
#include "../Player/Player.h"
#include "../Pokimac/Pokimac.h"
#include "./Event/Event.h"

#define MAP_DISPLAYED 0
#define FIGHT 1
#define POKIMAC_DEFEATED 2
#define PLAYER_DEFEATED 3

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
  Pokimac *pokimac;
  int game_mode;

  void combat(bool isAttack);
  void displayMap();
};