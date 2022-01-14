#include "Inventory.h"
#include "../../Game/Game.h"
#include "../Player.h"
#include "../../../../libs/consoleUtils.hpp"
#include "../../Pokimac/Pokimac.h"

Inventory::Inventory(){
    potion = 1;
    pokiball = 2;
    Pokimac *team[TEAM_CAPACITY];
    team[0]= new Pokimac;
    team[0]->setStarter();
    team_size=1;
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

Pokimac * Inventory::getTeam(){
    return team;
}

void Inventory::capturePoki(Pokimac * poki){
    if(team_size < TEAM_CAPACITY){
        team[team_size]=*poki;
        team_size++;
    }else{
        cout << "Plus de place dans l'équipe !"<<endl;
    }
}