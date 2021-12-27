#pragma once //c'est quoi ?

#define DISPLAY_VOID '.'
#define DISPLAY_POTION 'Potion'
#define DISPLAY_POKIBALL 'Pokiball'
#define SIZE_INVENTORY 10

using namespace std;

class Inventory {
    public :
        Inventory();

        void displayInventory();
        char getDisplayByCoords(int i);

    private :
        //int size = SIZE_INVENTORY;
        int items[SIZE_INVENTORY];
};