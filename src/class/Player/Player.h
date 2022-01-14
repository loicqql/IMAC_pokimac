
#pragma once
#include <string>
#include "../Pokimac/Pokimac.h"
#include "../Map/Map.h"
#include "../../../libs/consoleUtils.hpp"
#include "Inventory/Inventory.h"

using namespace std;

class Player {

  public:
    Player(Inventory *p_inventory);

    string getName();
    int getHealth();
    int getX();
    int getY();

    void setName(string username);

    int getExp();
    void addExp(int nbExp);

    void move(char dir);

    Inventory *inventory;
//Inventory getInventory();

  private:
    string name;
    //int health;
    //int damage;
    int exp;
    int x;
    int y;

    void clearCursor();
    void setCursor();
};