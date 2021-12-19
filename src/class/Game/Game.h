#pragma once

#include "../Map/Map.h"
#include "../Player/Player.h"

using namespace std;

class Game {
	public:
		Game(Player *p_player);
    void movePlayer(char dir);


	private:
    Map map;
    Player *player;

    void initPlayerAttack();

};