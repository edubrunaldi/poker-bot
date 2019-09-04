//
// Created by xima on 07/07/19.
//

#ifndef POKER_BOT_UTILS_HPP
#define POKER_BOT_UTILS_HPP


void testOpencv(char *);

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "opencv4/opencv2/highgui.hpp"
#include <exception>

/**
 * Path defaults, given that you are execute in poker-bot/:w
 */
 static std::string pathCommonsImages = "images/default/cropped/common";
 static std::string pathTable9Images = "images/default/cropped/9";
 static std::string pathButtons = "/buttons";


enum TableSize { MAX_2, MAX_3, MAX_6, MAX_9 };
enum StreetEnum  {PRE_FLOP_STREET, FLOP_STREET, TURN_STREET, RIVER_STREET};
enum Actions {FOLD_ACTION, CALL_ACTION, RAISE_BUTTON_1_ACTION, RAISE_BUTTON_2_ACTION, RAISE_BUTTON_3_ACTION, RAISE_BUTTON_4_ACTION};

enum PlayerPosition { P0, P1, P2, P3, P4, P5, P6, P7, P8};
struct Position {
  size_t x;
  size_t y;
};
enum CoordinateScreenEnum {
  pointX, pointY , imgWidth, imgHeight
};

enum ErrorsEnum {
  NOT_FOUND,
  NOT_ALLOCATED
};

const std::string ErrorsStrings[2] = {"Not found", "Not allocated"};

/*
  [0] = x inicial
  [1] = y inicial
  [2] = x final
  [3] = y final
 */
static int screenShotPosition[4] = {1360, 0, 1920, 1080};


struct ImageCoordinate {
  size_t x;
  size_t y;
  size_t width;
  size_t height;
};

void asyncWaitKeyStop(char key);

#endif //POKER_BOT_UTILS_HPP
