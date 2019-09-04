//
// Created by xima on 07/07/19.
//

#include "../../includes/BaseClasses/BaseImage.hpp"

/**
 * Retorna coodenadas da resolucao da tela do momento
 *
 */
int BaseImage::convertCropSizeToScreenSize(size_t i, CoordinateScreenEnum type) {
  switch (type) {
    case pointX:
      return (i * 1920) / screenShotPosition[2];
    case imgWidth:
      return (i * 1920) / screenShotPosition[2];
    case pointY:
      return (i * 1080) / screenShotPosition[3];
    case imgHeight:
      return (i * 1080) / screenShotPosition[3];
    default:
      throw "Error convertCropSize" + std::to_string(type);
  }
}

void BaseImage::crop(cv::Mat *original) {
  this->img.reset();
  // Setup a rectangle to define your region of interest
  cv::Rect myROI(
    this->imgPosition->x,
    this->imgPosition->y,
    this->imgPosition->width,
    this->imgPosition->height
  );

// Crop the full image to that image contained by the rectangle myROI
// Note that this doesn't copy the data
  this->img = std::make_unique<cv::Mat>((*original)(myROI));
}