#pragma once

#include <string>
#include <vector>

#include "../../../../libs/consoleUtils.hpp"

using namespace std;

class Event {
public:

  void addLog(string text);
  void clearLogs();

  void playerAttackPokimac();
  void PokimacAttackPlayer();

private:
  void initEvent();
  std::vector< string > logs;
};