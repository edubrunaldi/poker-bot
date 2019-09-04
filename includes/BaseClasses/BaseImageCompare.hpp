//
// Created by xima on 31/07/19.
//

#ifndef POKER_BOT_BASEIMAGECOMPARE_HPP
#define POKER_BOT_BASEIMAGECOMPARE_HPP

#include "../utils.hpp"
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgproc.hpp>

class BaseImageCompare {
protected:
  bool compare(cv::Mat *largestImage, std::unique_ptr<cv::Mat>& smallerImage, double threshold);
  bool compare(std::unique_ptr<cv::Mat>& largestImage, std::unique_ptr<cv::Mat>& smallerImage, double threshold);
};
#endif //POKER_BOT_BASEIMAGECOMPARE_HPP
