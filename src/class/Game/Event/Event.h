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

private:
  void initEvent();
  void displayLogs();
  std::vector<string> logs;
};