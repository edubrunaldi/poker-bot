#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-member-init"
//
// Created by xima on 07/08/19.
//

#include "../includes/Application.hpp"

Application::Application(int tableSizeNumber, bool autoExecute, bool mocked) {
  TableSize tableSize;
  switch (tableSizeNumber) {
    case 2:
      tableSize = MAX_2;
      break;
    case 3:
      tableSize = MAX_3;
      break;
    case 6:
      tableSize = MAX_6;
      break;
    case 9:
      tableSize = MAX_9;
      break;
    default:
      std::cout << "Tamanho da mesa desconhecido (Application::Application) : " + std::to_string(tableSizeNumber) << std::endl;
      throw;
  }
  this->game = std::make_unique<Game>(Game(tableSize, mocked, autoExecute));
}


void Application::setBigBlind(float bigBlindSize) {
  this->game->setBigBlind(bigBlindSize);
}

void Application::startGame() {
  this->game->start();
}
