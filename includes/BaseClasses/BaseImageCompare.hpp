//
// Created by xima on 31/07/19.
//

#ifndef MINECRAFT2_3_BASEIMAGECOMPARE_HPP
#define MINECRAFT2_3_BASEIMAGECOMPARE_HPP

#include "../utils.hpp"
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgproc.hpp>

class BaseImageCompare {
protected:
  bool compare(cv::Mat *largestImage, std::unique_ptr<cv::Mat>& smallerImage, double threshold);
  bool compare(std::unique_ptr<cv::Mat>& largestImage, std::unique_ptr<cv::Mat>& smallerImage, double threshold);
};
#endif //MINECRAFT2_3_BASEIMAGECOMPARE_HPP
