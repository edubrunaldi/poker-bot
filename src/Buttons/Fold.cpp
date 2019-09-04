//
// Created by xima on 05/08/19.
//

#include "../../includes/Buttons/Fold.hpp"

Fold::Fold(): BaseImage(), BaseImageCompare(), BaseMouse() {
  this->result = false;
  this->imgPosition = std::make_unique<ImageCoordinate>(ImageCoordinate());
  this->imgPosition->x = Fold::convertCropSizeToScreenSize(Fold::foldPosition.x, pointX);
  this->imgPosition->y = Fold::convertCropSizeToScreenSize(Fold::foldPosition.y, pointY);
  this->imgPosition->width = Fold::convertCropSizeToScreenSize(width, imgWidth);
  this->imgPosition->height = Fold::convertCropSizeToScreenSize(height, imgHeight);
  this->foldImg = std::make_unique<cv::Mat>(cv::imread(pathCommonsImages + pathButtons + "/fold.png"));
}

bool Fold::active() {
  return bool(this->result);
}

void Fold::compute(cv::Mat *src) {
  this->crop(src);
  this->result = this->compare(this->foldImg, this->img, this->threshold);
}

void Fold::accept(AbstractVisitor &visitor) {
  return visitor.visit(*this);
}

void Fold::click() {
  this->clickCoordinate(this->imgPosition->x, this->imgPosition->y, this->width, this->height);
}
