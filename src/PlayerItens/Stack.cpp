//
// Created by xima on 30/07/19.
//

#include "../../includes/PlayerItens/Stack.hpp"

Stack::Stack(): BaseImage(), BaseImageFindNumber() {
  this->result = 0;
  this->imgPosition = std::make_unique<ImageCoordinate>(ImageCoordinate());
  this->imgPosition->x = Stack::convertCropSizeToScreenSize(Stack::stackPosition.x, pointX);
  this->imgPosition->y = Stack::convertCropSizeToScreenSize(Stack::stackPosition.y, pointY);
  this->imgPosition->width = Stack::convertCropSizeToScreenSize(Stack::width, imgWidth);
  this->imgPosition->height = Stack::convertCropSizeToScreenSize(Stack::height, imgHeight);
  this->numbers = std::make_unique<std::vector<Numbers>>(std::vector<Numbers>({
    {"0", cv::imread(pathCommonsImages + pathStack +"/0.png")},
    {"1", cv::imread(pathCommonsImages + pathStack +"/1.png")},
    {"2", cv::imread(pathCommonsImages + pathStack +"/2.png")},
    {"3", cv::imread(pathCommonsImages + pathStack +"/3.png")},
    {"4", cv::imread(pathCommonsImages + pathStack +"/4.png")},
    {"5", cv::imread(pathCommonsImages + pathStack +"/5.png")},
    {"6", cv::imread(pathCommonsImages + pathStack +"/6.png")},
    {"7", cv::imread(pathCommonsImages + pathStack +"/7.png")},
    {"8", cv::imread(pathCommonsImages + pathStack +"/8.png")},
    {"9", cv::imread(pathCommonsImages + pathStack +"/9.png")},
    {".", cv::imread(pathCommonsImages + pathStack +"/dot.png")}}));
}


void Stack::compute(cv::Mat *src) {
  if (this->numbers->empty()) {
    std::cout << "No loaded images on AbstractImage::numbers" << std::endl;
    this->result = 0.0;
  }
  this->crop(src);
  this->result = this->findNumber(this->img, this->threshold);
}

float Stack::size() {
  return float(this->result);
}

void Stack::accept(AbstractVisitor &visitor) {
 return visitor.visit(*this);
}
