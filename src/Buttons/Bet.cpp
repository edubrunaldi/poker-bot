//
// Created by xima on 05/08/19.
//

#include "../../includes/Buttons/Bet.hpp"

Bet::Bet(): BaseImage(), BaseImageFindNumber(), BaseMouse() {
  this->result = 0;
  this->imgPosition = std::make_unique<ImageCoordinate>(ImageCoordinate());
  this->imgPosition->x = Bet::convertCropSizeToScreenSize(Bet::betPosition.x, pointX);
  this->imgPosition->y = Bet::convertCropSizeToScreenSize(Bet::betPosition.y, pointY);
  this->imgPosition->width = Bet::convertCropSizeToScreenSize(Bet::width, imgWidth);
  this->imgPosition->height = Bet::convertCropSizeToScreenSize(Bet::height, imgHeight);

  this->numbers = std::make_unique<std::vector<Numbers>>(std::vector<Numbers>({
    {"0", cv::imread(pathCommonsImages + pathBet + "/0.png")},
    {"1", cv::imread(pathCommonsImages + pathBet + "/1.png")},
    {"2", cv::imread(pathCommonsImages + pathBet + "/2.png")},
    {"3", cv::imread(pathCommonsImages + pathBet + "/3.png")},
    {"4", cv::imread(pathCommonsImages + pathBet + "/4.png")},
    {"5", cv::imread(pathCommonsImages + pathBet + "/5.png")},
    {"6", cv::imread(pathCommonsImages + pathBet + "/6.png")},
    {"7", cv::imread(pathCommonsImages + pathBet + "/7.png")},
    {"8", cv::imread(pathCommonsImages + pathBet + "/8.png")},
    {"9", cv::imread(pathCommonsImages + pathBet + "/9.png")},
    {".", cv::imread(pathCommonsImages + pathBet + "/dot.png")}}));
}

void Bet::compute(cv::Mat *src) {
  if (this->numbers->empty()) {
    std::cout << "No loaded images on AbstractImage::numbers" << std::endl;
    this->result = 0.0;
  }
  this->crop(src);
  this->result = this->findNumber(this->img, this->threshold);
}

float Bet::size() {
  return float(this->result);
}

void Bet::accept(AbstractVisitor& visitor) {
  return visitor.visit(*this);
}

void Bet::click() {
  this->clickCoordinate(this->imgPosition->x, this->imgPosition->y, this->width, this->height);
}
