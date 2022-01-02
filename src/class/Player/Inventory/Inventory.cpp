#include "Inventory.h"
#include "../../Game/Game.h"
#include "../Player.h"
#include "../../../../libs/consoleUtils.hpp"

Inventory::Inventory(){
    potion = 1;
    pokiball = 2;
}

int Inventory::getNbItem(int item){
    if(item == 0){
        return potion;
    }else if(item == 1){
        return pokiball;
    }
    return -1;
}

void Inventory::displayInventory(){
    cout << endl << "Inventaire :" << endl;
    cout << "x: Utiliser potion : reste " << potion << endl;
    cout << "c: Utiliser pokiball : reste " << pokiball << endl;
    cout << endl << "";
}

void Inventory::rmItem(int item){
    if(item == 0){
        cout << "Vous avez utilisé une potion de soin : +20 pv"<<endl;
        potion--;
    }else if(item == 1){
        cout << "Vous avez utilisé une pokiball"<<endl;
        pokiball--;
    }
}

void Inventory::addItem(int item){
    if(item == 0){
        potion++;
    }else if(item == 1){
        pokiball++;
    }
}