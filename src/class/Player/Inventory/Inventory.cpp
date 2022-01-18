#include "Inventory.h"
#include "../../Game/Game.h"
#include "../Player.h"
#include "../../../../libs/consoleUtils.hpp"
#include "../../Pokimac/Pokimac.h"

Inventory::Inventory(){
    potion = 1;
    pokiball = 2;
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
    cout << "espace: Revenir au combat" << endl;
    cout << endl << "";
}

void Inventory::rmItem(int item){
    if(item == 0){
        //cout << "Vous avez utilisé une potion de soin : +20 pv"<<endl;
        potion--;
    }else if(item == 1){
        //cout << "Vous avez utilisé une pokiball"<<endl;
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
    return *team;
}

void Inventory::addPoki(Pokimac * poki){
    if(team_size < TEAM_CAPACITY){
        team[team_size]= poki;
        poki->setDefeated(true);
        team_size++;
    }else{
        cout << "Erreur. Plus de place."<<endl;
    }
}

void Inventory::showTeam(){
    cout << "espace: revenir au combat" << endl;
    for(int i=0;i< team_size;i++){
        cout << i+1 << ". " << team[i]->getName() << " : " << team[i]->getHealth() << " pv | " << team[i]->getDamage() << " dmg "<<endl;
    }
}

int Inventory::getTeamSize(){
    return team_size;
}