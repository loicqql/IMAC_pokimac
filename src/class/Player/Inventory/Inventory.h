#pragma once

#define DISPLAY_VOID '.'
#define DISPLAY_POTION 'Potion'
#define DISPLAY_POKIBALL 'Pokiball'

using namespace std;

class Inventory {
    public :
        Inventory();

        int getNbPotion();
        int getNbPokiball();
        void displayInventory();
        void rmPotion();
        void rmPokiball();
        void addPotion();
        void addPokiball();
        
        //void displayInventory();

    private :
        //int size = SIZE_INVENTORY;
        //vector<Item> items[SIZE_INVENTORY];
        int potion;
        int pokiball;
};