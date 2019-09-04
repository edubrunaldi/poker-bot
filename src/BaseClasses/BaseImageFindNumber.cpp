//
// Created by xima on 31/07/19.
//

#include "../../includes/BaseClasses/BaseImageFindNumber.hpp"

float BaseImageFindNumber::findNumber(std::unique_ptr<cv::Mat> &img, float threshold) {

  std::vector<NumberPoint> numbersFound;
  cv::Mat result;
  cv::Mat fixedImgs = cv::Mat(*img);
  cv::cvtColor(fixedImgs, fixedImgs, cv::ColorConversionCodes::COLOR_BGR2GRAY);

  for(const auto& number: *this->numbers) {
    cv::Mat cropImg = cv::Mat(number.img);
    cv::cvtColor(cropImg, cropImg, cv::ColorConversionCodes::COLOR_BGR2GRAY);
    // Do the matcing and normalize
    cv::matchTemplate(fixedImgs, cropImg, result, cv::TM_CCOEFF_NORMED);
    // Localizing the best match with minmaxLoc
    double minVal, maxVal;
    cv::Point minLoc, maxLoc;
    cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, cv::Mat());
    for (int i = 0; i < result.rows; ++i) {
      for (int j = 0; j < result.cols; ++j) {
        auto point = result.at<float>(i, j);
        if ( point >= threshold) {
          NumberPoint p;
          p.name = number.numberName;
          p.x = j;
          numbersFound.push_back(p);
        }
      }
    }
  }
  std::sort(numbersFound.begin(), numbersFound.end());
  std::string sizeString;
  for(const auto &item: numbersFound) {
    sizeString += item.name;
  }
  if(!sizeString.empty())
    while(sizeString[0] == '.')
      sizeString.erase(0,1);
  return sizeString.empty() ? 0.0 : std::stod(sizeString);
}
