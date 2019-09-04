//
// Created by xima on 05/08/19.
//

#include "../../includes/Buttons/RaiseButton.hpp"

RaiseButton::RaiseButton(int buttonNumber): BaseMouse() {
  if (buttonNumber > 3) {
    std::cout << "buttonNumber maior que 3 : " << buttonNumber << std::endl;
    throw;
  }
  this->p = Position();
  this->p.x = RaiseButton::raisePosition[buttonNumber].x;
  this->p.y = RaiseButton::raisePosition[buttonNumber].y;
}

void RaiseButton::click() {
  this->clickCoordinate(this->p.x, this->p.y, this->width, this->height);
}
