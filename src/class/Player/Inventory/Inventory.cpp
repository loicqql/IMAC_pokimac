#include "Inventory.h"
#include "../../Game/Game.h"
#include "../Player/Player.h"
#include "../../../../libs/consoleUtils.hpp"

Inventory::Inventory(){
    pokiball = 2;
    potion = 0;
}

int Inventory::getNbPotion(){
    return potion;
}

int Inventory::getNbPokiball(){
    return pokiball;
}

void Inventory::displayInventory(){
    cout << endl << "Items disponibles : " << endl;
    cout << "Pokiballs : " << pokiball << endl;
    cout << "Potions : " << potion << endl;
}

void Inventory::rmPotion(){
    potion--;
}

void Inventory::rmPokiball(){
    pokiball--;
}

void Inventory::addPotion(){
    potion++;
}

void Inventory::addPokiball(){
    pokiball++;
}