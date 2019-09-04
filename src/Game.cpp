//
// Created by xima on 07/07/19.
//

#include "../includes/Game.hpp"

Game::Game(TableSize tableSize, bool mocked, bool autoExecute) {
  this->autoExecute = autoExecute;
  this->imgVisitor = std::make_unique<ImageVisitor>(ImageVisitor(false));
  this->table = std::make_unique<Table>(Table(tableSize));
  this->mouse = std::make_unique<BaseMouse>(BaseMouse());
//  this->smallBall = SmallBall();
  this->actualHand = "";
}

void Game::setBigBlind(float bigBlind) {
  this->table->setBigBlind(bigBlind);
}

void Game::start() {
//  std::thread t1(asyncWaitKeyStop, 'q');
//  std::thread t2(&Game::playing, this);
//  t1.join();
//  this->stop = true;
//  t2.join();
  this->playing();
}

void Game::playing() {
  while(!this->stop) {
    this->captureImage();

    if(!this->userTurn() || this->table->getHand().empty())
      continue;

    PokerVariables itens;
    auto street = this->street();
    Actions actions = FOLD_ACTION;
    // define action here
    switch (street) {
      case PRE_FLOP_STREET:
        itens.streetPoker = PRE_FLOP_STREET_POKER;
        this->preflop();
        break;
      case FLOP_STREET:
        itens.streetPoker = FLOP_STREET_POKER;
        this->flop();
        break;
      case TURN_STREET:
        itens.streetPoker = TURN_STREET_POKER;
        this->turn();
        break;
      case RIVER_STREET:
        itens.streetPoker = RIVER_STREET_POKER;
        this->river();
        break;
    }
    this->executeAction(actions);
    this->waitFinishUserTurn();
  }
}

void Game::captureImage() {
  this->imgVisitor->takePicture();
  this->table->accept(*this->imgVisitor);
}

bool Game::userTurn() {
  return this->table->foldActive() || this->table->getBetSize() > 0.01;
}

StreetEnum Game::street() {
  return this->table->getStreet();
}

void Game::preflop() {
  std::cout << "PRE FLOP" << std::endl;
  auto hand = this->table->getHand();
  if (hand != this->actualHand)
    this->actualHand = hand; // nova mao, novo street
}

void Game::flop() {
  std::cout << "FLOP" << std::endl;
}

void Game::turn() {
  std::cout << "TURN" << std::endl;
}

void Game::river() {
  std::cout << "RIVER" << std::endl;
}

void Game::executeAction(Actions action) {
  if(this->autoExecute) {
    this->table->makeAction(action);
    this->mouse->move(0,0);
  }
  switch (action) {
    case FOLD_ACTION:
      std::cout << "--------------------" << std::endl;
      std::cout << "---   ######     ---" << std::endl;
      std::cout << "---   #          ---" << std::endl;
      std::cout << "---   ###        ---" << std::endl;
      std::cout << "---   #          ---" << std::endl;
      std::cout << "---   #          ---" << std::endl;
      std::cout << "--------------------" << std::endl;
      break;
    case CALL_ACTION:
      std::cout << "--------------------" << std::endl;
      std::cout << "---   ######     ---" << std::endl;
      std::cout << "---   #          ---" << std::endl;
      std::cout << "---   #          ---" << std::endl;
      std::cout << "---   #          ---" << std::endl;
      std::cout << "---   ######     ---" << std::endl;
      std::cout << "--------------------" << std::endl;
      break;
    case RAISE_BUTTON_1_ACTION:
      std::cout << "-----------------------" << std::endl;
      std::cout << "---   #####   ####  ---" << std::endl;
      std::cout << "---   #   #     #   ---" << std::endl;
      std::cout << "---   ####     #    ---" << std::endl;
      std::cout << "---   # #     #     ---" << std::endl;
      std::cout << "---   #  #   ####   ---" << std::endl;
      std::cout << "-----------------------" << std::endl;
      break;
    case RAISE_BUTTON_2_ACTION:
      std::cout << "------------------------" << std::endl;
      std::cout << "---   #####   ####   ---" << std::endl;
      std::cout << "---   #   #      #   ---" << std::endl;
      std::cout << "---   ####    ####   ---" << std::endl;
      std::cout << "---   # #        #   ---" << std::endl;
      std::cout << "---   #  #    ####   ---" << std::endl;
      std::cout << "------------------------" << std::endl;
      break;
    case RAISE_BUTTON_3_ACTION:
      std::cout << "------------------------" << std::endl;
      std::cout << "---   #####   #  #   ---" << std::endl;
      std::cout << "---   #   #   #  #   ---" << std::endl;
      std::cout << "---   ####    ####   ---" << std::endl;
      std::cout << "---   # #        #   ---" << std::endl;
      std::cout << "---   #  #       #   ---" << std::endl;
      std::cout << "------------------------" << std::endl;
      break;
    case RAISE_BUTTON_4_ACTION:
      std::cout << "------------------------" << std::endl;
      std::cout << "---   #####   #####  ---" << std::endl;
      std::cout << "---   #   #   #      ---" << std::endl;
      std::cout << "---   ####    ####   ---" << std::endl;
      std::cout << "---   # #        #   ---" << std::endl;
      std::cout << "---   #  #    ####   ---" << std::endl;
      std::cout << "------------------------" << std::endl;
      break;
  }
}

void Game::waitFinishUserTurn() {
  while(this->table->foldActive() || this->table->getBetSize() > 0.01)
    this->captureImage();
}

