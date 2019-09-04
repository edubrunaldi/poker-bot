// Created by xima on 07/07/19.
//

#ifndef POKER_BOT_GAME_HPP
#define POKER_BOT_GAME_HPP

#include "utils.hpp"
#include "ImageVisitor.hpp"
#include "TableItens/Table.hpp"
#include <opencv4/opencv2/highgui.hpp>
#include <thread>

class Game {
private:
  std::unique_ptr<ImageVisitor> imgVisitor;
  std::unique_ptr<Table> table;
  std::unique_ptr<BaseMouse> mouse;
  std::string actualHand;
  bool stop = false;
  bool autoExecute;
  void executeAction(Actions action);

public:
  explicit Game(TableSize tableSize, bool mocked = false, bool autoExecute = false);
  void setBigBlind(float bigBlind);
  void start();
  void playing();
  void captureImage();
  bool userTurn();
  StreetEnum street();
  void preflop();
  void flop();
  void turn();
  void river();
  void waitFinishUserTurn();
};

#endif //POKER_BOT_GAME_HPP

