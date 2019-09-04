//
// Created by xima on 01/08/19.
//

#ifndef POKER_BOT_BASEMOUSE_HPP
#define POKER_BOT_BASEMOUSE_HPP

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstring>
#include <zconf.h>
#include "../utils.hpp"
#include <random>

class BaseMouse {
public:
  Display* display;
  Window root;

  explicit BaseMouse();

  void clickCoordinate(int x, int y, int width, int height);
  Position randPosition(int width, int height);

  void move(int x, int y);
  void move(Position p, int x, int y);
};
#endif //POKER_BOT_BASEMOUSE_HPP
