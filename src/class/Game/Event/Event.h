#pragma once

#include <string>
#include <vector>

#include "../../../../libs/consoleUtils.hpp"
#include "../../Player/Player.h"
#include "../../Pokimac/Pokimac.h"

using namespace std;

class Event {
public:

  void addLog(string text);
  void clearLogs();

  void playerAttackPokimac(Player *p_player, Pokimac *p_pokimac);
  void pokimacDefeated(Pokimac *p_pokimac);
  void playerDefeated();
  void pokimacCaught(Pokimac *p_pokimac);
  void displayInventory(Player *p_player);
  void displayMessage(string text);

private:
  void initEvent();
  void displayLogs();
  std::vector<string> logs;
};