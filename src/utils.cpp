//
// Created by xima on 07/07/19.
//

#include <iostream>
#include "../includes/utils.hpp"
void asyncWaitKeyStop(char key) {
  char c = 'a';
  while(c != key) {
    std::cin.get(c);
  }
}