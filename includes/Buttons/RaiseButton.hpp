//
// Created by xima on 05/08/19.
//

#ifndef MINECRAFT2_3_RAISEBUTTON_HPP
#define MINECRAFT2_3_RAISEBUTTON_HPP

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
#endif //MINECRAFT2_3_RAISEBUTTON_HPP
