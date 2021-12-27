#include <string>
#include "Inventory.h"
#include "../../../../libs/consoleUtils.hpp"

Inventory::Inventory(){
    int items[SIZE_INVENTORY]={1,1,0,0,0,0,0,0,0,0};
}

void Inventory::displayInventory(){
    char charDisplay;
    for(int i=0;i<SIZE_INVENTORY;i++){
        cout << " | " << getDisplayByCoords(i) << " | ";
    }
}

char Inventory::getDisplayByCoords(int i){
    char charDisplay;
    switch (items[i]){
        case 1:
            charDisplay = DISPLAY_POTION;
            break;
        case 2:
            charDisplay = DISPLAY_POKIBALL;
            break;
        default:
            charDisplay = DISPLAY_VOID;
            break;
    }

}