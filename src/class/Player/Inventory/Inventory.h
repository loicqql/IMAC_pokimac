#pragma once

#define DISPLAY_VOID '.'
#define DISPLAY_POTION 'Potion'
#define DISPLAY_POKIBALL 'Pokiball'

using namespace std;

class Inventory {
    public :
        Inventory();

        //pour int item > potion = 0 / pokiball = 1
        int getNbItem(int item);
        void displayInventory();
        void rmItem(int item);
        void addItem(int item);

    private :
        //int size = SIZE_INVENTORY;
        //vector<Item> items[SIZE_INVENTORY];
        int potion;
        int pokiball;
};