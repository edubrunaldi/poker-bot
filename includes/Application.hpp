//
// Created by xima on 07/08/19.
//

#ifndef POKER_BOT_APPLICATION_HPP
#define POKER_BOT_APPLICATION_HPP

#include <bits/unique_ptr.h>
#include "Game.hpp"

class Application {
private:
  std::unique_ptr<Game> game;
public:
  explicit Application(int  tableSize, bool autoExecute, bool mocked = false);
  void setBigBlind(float bigBlind);
  void startGame();
};
#endif //POKER_BOT_APPLICATION_HPP
