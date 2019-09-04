//
// Created by xima on 31/07/19.
//

#include "../../includes/TableItens/Pot.hpp"

Pot::Pot(): BaseImage(), BaseImageFindNumber() {
  this->result = 0;
  this->imgPosition = std::make_unique<ImageCoordinate>(ImageCoordinate());
  this->imgPosition->x = Pot::convertCropSizeToScreenSize(Pot::potPosition.x, pointX);
  this->imgPosition->y = Pot::convertCropSizeToScreenSize(Pot::potPosition.y, pointY);
  this->imgPosition->width = Pot::convertCropSizeToScreenSize(Pot::width, imgWidth);
  this->imgPosition->height = Pot::convertCropSizeToScreenSize(Pot::height, imgHeight);
  this->numbers = std::make_unique<std::vector<Numbers>>(std::vector<Numbers>({
   {"0", cv::imread(pathCommonsImages + pathPot + "/0.png")},
   {"1", cv::imread(pathCommonsImages + pathPot + "/1.png")},
   {"2", cv::imread(pathCommonsImages + pathPot + "/2.png")},
   {"3", cv::imread(pathCommonsImages + pathPot + "/3.png")},
   {"4", cv::imread(pathCommonsImages + pathPot + "/4.png")},
   {"5", cv::imread(pathCommonsImages + pathPot + "/5.png")},
   {"6", cv::imread(pathCommonsImages + pathPot + "/6.png")},
   {"7", cv::imread(pathCommonsImages + pathPot + "/7.png")},
   {"8", cv::imread(pathCommonsImages + pathPot + "/8.png")},
   {"9", cv::imread(pathCommonsImages + pathPot + "/9.png")},
   {".", cv::imread(pathCommonsImages + pathPot + "/dot.png")}}));
}

void Pot::compute(cv::Mat *src) {
  if (this->numbers->empty()) {
    std::cout << "No loaded images on AbstractImage::numbers" << std::endl;
    this->result = 0.0;
  }
  this->crop(src);
  this->result = this->findNumber(this->img, this->threshold);
}

float Pot::size() {
  return float(this->result);
}

void Pot::accept(AbstractVisitor& visitor) {
  return visitor.visit(*this);
}
