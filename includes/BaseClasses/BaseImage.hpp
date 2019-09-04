//
// Created by xima on 07/07/19.
//

#ifndef POKER_BOT_BASEIMAGE_HPP
#define POKER_BOT_BASEIMAGE_HPP

#include <iostream>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include "../utils.hpp"



class BaseImage {
protected:
  std::unique_ptr<ImageCoordinate> imgPosition;
  std::unique_ptr<cv::Mat> img;

  static int convertCropSizeToScreenSize(size_t, CoordinateScreenEnum type);

  void crop(cv::Mat *original);
};

#endif //POKER_BOT_BASEIMAGE_HPP
