#pragma once
#include <string>

using namespace std;

class Pokimac {

  public:
    Pokimac();

    string getName();
    int getHealth();
    void setHealth(int nbDamage);
    int getDamage();
    int getExp();
    int getX();
    int getY();

    void setName(string username);
    void addDamage(int nbDamage);
    void setCoords(int coords);
    

  private:
    string name;
    int health;
    int damage;
    int exp;
    int x;
    int y;
};