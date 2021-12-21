#pragma once
#include <string>
#include "../Pokimac/Pokimac.h"
#include "../Map/Map.h"
#include "../../../libs/consoleUtils.hpp"

using namespace std;

class Player {

  public:
    Player();

    string getName();
    int getHealth();
    int getX();
    int getY();

    void setName(string username);
    void addHealth(int nbHealth);
    
    void setHealth(int nbDamage);

    int getDamage();
    void addDamage(int nbDamage);

    int getExp();
    void addExp(int nbExp);

    int attack(Pokimac *p_pokimac);
    void move(char dir);
    
  private:
    string name;
    int health;
    int damage;
    int exp;
    int x;
    int y;

    void clearCursor();
    void setCursor();
};