#pragma once

#include "../../Pokimac/Pokimac.h"

#define DISPLAY_VOID '.'
#define DISPLAY_POTION 'Potion'
#define DISPLAY_POKIBALL 'Pokiball'

#define TEAM_CAPACITY 6

using namespace std;

class Inventory {
    public :
        Inventory();

        //pour int item > potion = 0 / pokiball = 1
        int getNbItem(int item);
        void rmItem(int item);
        void addItem(int item);

        //team
        Pokimac * getTeam();
        void addPoki(Pokimac * poki);
        void showTeam();
        int getTeamSize();
        bool switchPokimac(int numPoki);
        void rmFirstPoki();

    private :
        int potion;
        int pokiball;
        Pokimac * team[TEAM_CAPACITY];
        int team_size;
};