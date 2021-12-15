#pragma once
#include <string>
#include "Pokimac.h"

using namespace std;

class Player {

  public:
    Player();
    Player(int nbHealth);

    string getName();
    int getHealth();

    void setName(string username);
    void setHealth(int nbHealth);
    void setDamage(int nbDamage);

    void attack(Pokimac &pokimac);
    
  private:
    string name;
    int health;
};