//
// Created by xima on 31/07/19.
//

#ifndef POKER_BOT_BASEIMAGEFINDNUMBER_HPP
#define POKER_BOT_BASEIMAGEFINDNUMBER_HPP

#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <iostream>


struct Numbers {
  std::string numberName;
  cv::Mat img;
};
struct NumberPoint {
  std::string name;
  int x;
  bool operator<(const NumberPoint &p) const {return x < p.x;}
};


class BaseImageFindNumber {
protected:
  std::unique_ptr<std::vector<Numbers>> numbers;
  float findNumber(std::unique_ptr<cv::Mat> &img, float threshold);
};
#endif //POKER_BOT_BASEIMAGEFINDNUMBER_HPP
