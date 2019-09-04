//
// Created by xima on 05/08/19.
//

#include "../../includes/Buttons/Call.hpp"

Call::Call(): BaseImage(), BaseImageFindNumber(), BaseMouse() {
  this->result = 0;
  this->imgPosition = std::make_unique<ImageCoordinate>(ImageCoordinate());
  this->imgPosition->x = Call::convertCropSizeToScreenSize(Call::callPosition.x, pointX);
  this->imgPosition->y = Call::convertCropSizeToScreenSize(Call::callPosition.y, pointY);
  this->imgPosition->width = Call::convertCropSizeToScreenSize(Call::width, imgWidth);
  this->imgPosition->height = Call::convertCropSizeToScreenSize(Call::height, imgHeight);

  this->numbers = std::make_unique<std::vector<Numbers>>(std::vector<Numbers>({
    {"0", cv::imread(pathCommonsImages + pathCall + "/0.png")},
    {"1", cv::imread(pathCommonsImages + pathCall + "/1.png")},
    {"2", cv::imread(pathCommonsImages + pathCall + "/2.png")},
    {"3", cv::imread(pathCommonsImages + pathCall + "/3.png")},
    {"4", cv::imread(pathCommonsImages + pathCall + "/4.png")},
    {"5", cv::imread(pathCommonsImages + pathCall + "/5.png")},
    {"6", cv::imread(pathCommonsImages + pathCall + "/6.png")},
    {"7", cv::imread(pathCommonsImages + pathCall + "/7.png")},
    {"8", cv::imread(pathCommonsImages + pathCall + "/8.png")},
    {"9", cv::imread(pathCommonsImages + pathCall + "/9.png")},
    {".", cv::imread(pathCommonsImages + pathCall + "/dot.png")}}));
}

void Call::compute(cv::Mat *src) {
  if (this->numbers->empty()) {
    std::cout << "No loaded images on AbstractImage::numbers" << std::endl;
    this->result = 0.0;
  }
  this->crop(src);
  this->result = this->findNumber(this->img, this->threshold);
}

float Call::size() {
  return float(this->result);
}

void Call::accept(AbstractVisitor& visitor) {
  return visitor.visit(*this);
}

void Call::click() {
  this->clickCoordinate(this->imgPosition->x, this->imgPosition->y, this->width, this->height);
}
