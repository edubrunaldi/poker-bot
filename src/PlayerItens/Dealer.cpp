//
// Created by xima on 30/07/19.
//

#include "../../includes/PlayerItens/Dealer.hpp"

Dealer::Dealer(PlayerPosition playerPosition, TableSize tableSize): BaseImage(), BaseImageCompare() {
  this->result = false;
  size_t position = 0;
  switch (playerPosition) {
    case P0:
      position = 1;
    case P1:
      position = 1;
      break;
    case P2:
      position = 2;
      break;
    case P3:
      position = 3;
      break;
    case P4:
      position = 4;
      break;
    case P5:
      position = 5;
      break;
    case P6:
      position = 6;
      break;
    case P7:
      position = 7;
      break;
    case P8:
      position = 8;
      break;
    default:
      throw "PlayerStatus:: Posicao nao encontrada";
  }
  switch (tableSize) {

    case MAX_2:
      std::cout << "Nao existe dealer para 2 usuario, mocando para 9" << std::endl;
      this->dealerImg = cv::imread(pathTable9Images + pathDealers + "/p" + std::to_string(position) + ".png");
      break;
    case MAX_3:
      std::cout << "Nao existe dealer para 3 usuario, mocando para 9" << std::endl;
      this->dealerImg = cv::imread(pathTable9Images + pathDealers + "/p" + std::to_string(position) + ".png");
      break;
    case MAX_6:
      std::cout << "Nao existe dealer para 6 usuario, mocando para 9" << std::endl;
      this->dealerImg = cv::imread(pathTable9Images + pathDealers + "/p" + std::to_string(position) + ".png");
      break;
    case MAX_9:
      this->dealerImg = cv::imread(pathTable9Images + pathDealers + "/p" + std::to_string(position) + ".png");
      break;
  }
  this->imgPosition = std::make_unique<ImageCoordinate>(ImageCoordinate());
  this->imgPosition->x = Dealer::convertCropSizeToScreenSize(Dealer::dealerPosition[position ].x,
                                                                   pointX);
  this->imgPosition->y = Dealer::convertCropSizeToScreenSize(Dealer::dealerPosition[position].y,
                                                                   pointY);
  this->imgPosition->width = Dealer::convertCropSizeToScreenSize(Dealer::width, imgWidth);
  this->imgPosition->height = Dealer::convertCropSizeToScreenSize(Dealer::height, imgHeight);
}

void Dealer::compute(cv::Mat *src) {
  this->crop(src);
  this->result = this->compare(&this->dealerImg, this->img, this->threshold);
}

bool Dealer::dealer() {
  return bool(this->result);
}

void Dealer::accept(AbstractVisitor &visitor) {
  return visitor.visit(*this);
}
