
#include <iostream>
#include "../includes/Application.hpp"
#include <unistd.h>

int menu(float bigBling, int tableSize, bool bot);
void startGame(std::unique_ptr<Application>& app, float bigBlind);

int main() {
  // printa o path que o programa esta rodando
  char currentPath[FILENAME_MAX];
  getcwd(currentPath, sizeof(currentPath));
  std::cout << "Current Path: " << currentPath << std::endl;
  std::unique_ptr<Application> application;
  bool playing = true;
  bool bot = false;
  float bigBling = 0.0;
  float bigBlindValue = 0.0;
  int tableSize = 0;
  int tableSizeValue = 0;
  int botValue = 0;
  int response = 40;
  while(playing) {
    if ((response == 1 || response == 2) && (bigBling != 0.0 && tableSize != 0)) {
      tableSize = 0;
      bigBling = 0.0;
      application.reset();
    }
    response = menu(bigBling, tableSize, bot);
    if (response == 1 || response == 2) {
      if (bigBling == 0.0) {
        std::cout << "Preencha o valor do bigBlind antes de jogar" << std::endl << std::endl;
        continue;
      }
      if (tableSize == 0) {
        std::cout << "Preencha o tamanho da mesa antes de jogar" << std::endl << std::endl;
        continue;
      }
    }
    switch (response) {
      case 0:
        playing = false;
        break;
      case 1:
        application = std::make_unique<Application>(Application(tableSize, bot));
        startGame(application, bigBling);
        break;
      case 2:
        application = std::make_unique<Application>(Application(tableSize, false, true));
        startGame(application, bigBling);
        break;
      case 3:
        std::cout << "Valor do bigBlind > ";
        std::cin >> bigBlindValue;
        bigBling = bigBlindValue;
        break;
      case 4:
        std::cout << "Tamanho da mesa > ";
        std::cin >> tableSizeValue;
        tableSize = tableSizeValue;
        break;
      case 5:
        std::cout << "use bot (1(y)/0(N)): ";
        std::cin >> botValue;
        bot = botValue != 0;
        break;
    }
  }
  return 0;
}


int menu(float bigBling, int tableSize, bool bot) {
  int response = -1;
  int result = 0;
  while(response < 0 || response > 6) {
    std::cout << "Minecraft 2.3 - Seja bem vindo!" << std::endl;
    std::cout << "bigBlind = " << bigBling << "      " << "tableSize = " << tableSize << "   bot status: " << bot << std::endl << std::endl;
    std::cout << "0) Quit" << std::endl;
    std::cout << "1) Play" << std::endl;
    std::cout << "2) Play with mocked image (test)" << std::endl;
    std::cout << "3) change big blind" << std::endl;
    std::cout << "4) change table size" << std::endl;
    std::cout << "5) change bot" << std::endl;
    std::cout << "6) Some test" << std::endl;
    std::cin >> result;
    response = result;
  }
  return response;
}

void startGame(std::unique_ptr<Application>& app, float bigBlind) {
  app->setBigBlind(bigBlind);
  app->startGame();
}
