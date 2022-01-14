#pragma once

#include "../../Pokimac/Pokimac.h"

#define DISPLAY_VOID '.'
#define DISPLAY_POTION 'Potion'
#define DISPLAY_POKIBALL 'Pokiball'

#define TEAM_CAPACITY 15

using namespace std;

class Inventory {
    public :
        Inventory();

        //pour int item > potion = 0 / pokiball = 1
        int getNbItem(int item);
        void displayInventory();
        void rmItem(int item);
        void addItem(int item);

        //team
        Pokimac * getTeam();
        void capturePoki(Pokimac * poki);

    private :
        //int size = SIZE_INVENTORY;
        //vector<Item> items[SIZE_INVENTORY];
        int potion;
        int pokiball;
        Pokimac *team;
        int team_size;
};