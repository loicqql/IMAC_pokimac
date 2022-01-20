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

void Inventory::rmItem(int item){
    if(item == 0){
        potion--;
    }else if(item == 1){
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

void Inventory::rmFirstPoki(){
    for(int i=0;i<team_size-1;i++){
        team[i]=team[i+1];
    }
    team[team_size]=nullptr;
    team_size--;
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
    char letters[7] = {'a', 'z', 'e', 'r', 't', 'y', '\0' };
    cout << "espace: revenir au combat" << endl;
    if(team_size>1){
        cout << "Appuyer sur une des lettres pour changer de pokimac" << endl;
    }
    cout << "Équipe :" << endl;
    char letter;
    cout << team[0]->getName() << " : " << team[0]->getHealth() << " pv | " << team[0]->getDamage() << " dmg | " << team[0]->getExp() << " % d\'xp (en combat)"<<endl; 
    for(int i=1;i< team_size;i++){
        letter = letters[i-1];
        cout << letter << ". " << team[i]->getName() << " > " << team[i]->getHealth() << " pv | " << team[i]->getDamage() << " dmg | " << team[i]->getExp() << " % d\'xp" <<endl;
    }
}

int Inventory::getTeamSize(){
    return team_size;
}

bool Inventory::switchPokimac(int numPoki){
    if(team_size>numPoki){
        Pokimac *temp;
        temp = team[0];
        team[0]=team[numPoki];
        team[numPoki]=temp;
        return true;
    }else{
        return false;
    }
}