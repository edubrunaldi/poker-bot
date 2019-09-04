//
// Created by xima on 05/08/19.
//

#ifndef POKER_BOT_RAISEBUTTON_HPP
#define POKER_BOT_RAISEBUTTON_HPP

#include "../BaseClasses/BaseMouse.hpp"

class RaiseButton: public BaseMouse {
private:
  constexpr const static Position raisePosition[4] = {{1288, 840}, {1451, 840}, {1621, 840}, {1781, 840}};
  const int width = 125, height = 31;
  Position p{};
public:
  explicit RaiseButton(int buttonNumber);
  void click();
};
#endif //POKER_BOT_RAISEBUTTON_HPP
