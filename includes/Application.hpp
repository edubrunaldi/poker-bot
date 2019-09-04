//
// Created by xima on 07/08/19.
//

#ifndef MINECRAFT2_3_APPLICATION_HPP
#define MINECRAFT2_3_APPLICATION_HPP

#include <bits/unique_ptr.h>
#include "Game.hpp"

class Application {
private:
  Game* game;
public:
  explicit Application(int  tableSize, bool autoExecute, bool mocked = false);
  ~Application();
  void setBigBlind(float bigBlind);
  void startGame();
};
#endif //MINECRAFT2_3_APPLICATION_HPP
