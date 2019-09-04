//
// Created by xima on 27/07/19.
//

#include "../../includes/PlayerItens/PlayerStatus.hpp"


PlayerStatus::PlayerStatus(PlayerPosition playerPosition, TableSize tableSize): BaseImage(), BaseImageCompare() {
  this->result = false;
  size_t position = 0;
  switch (playerPosition) {
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
      std::cout <<  "PlayerStatus:: Posicao nao encontrada" << std::endl;
      throw;
  }
  switch (tableSize) {

    case MAX_2:
      std::cout << "Nao existe playerStatus para mesa de 2, criando para mesa de 9" << std::endl;
      this->playingStatusImg = cv::imread(pathTable9Images + pathPlayerStatus + "/p" + std::to_string(position) + ".png");
      break;
    case MAX_3:
      std::cout << "Nao existe playerStatus para mesa de 3, criando para mesa de 9" << std::endl;
      this->playingStatusImg = cv::imread(pathTable9Images + pathPlayerStatus + "/p" + std::to_string(position) + ".png");
      break;
    case MAX_6:
      std::cout << "Nao existe playerStatus para mesa de 6, criando para mesa de 9" << std::endl;
      this->playingStatusImg = cv::imread(pathTable9Images + pathPlayerStatus + "/p" + std::to_string(position) + ".png");
      break;
    case MAX_9:
      this->playingStatusImg = cv::imread(pathTable9Images + pathPlayerStatus + "/p" + std::to_string(position) + ".png");
      break;
  }

  this->imgPosition = std::make_unique<ImageCoordinate>(ImageCoordinate());
  this->imgPosition->x = PlayerStatus::convertCropSizeToScreenSize(PlayerStatus::playersPositions[position - 1].x,
                                                                   pointX);
  this->imgPosition->y = PlayerStatus::convertCropSizeToScreenSize(PlayerStatus::playersPositions[position - 1].y,
                                                                   pointY);
  this->imgPosition->width = PlayerStatus::convertCropSizeToScreenSize(PlayerStatus::width, imgWidth);
  this->imgPosition->height = PlayerStatus::convertCropSizeToScreenSize(PlayerStatus::height, imgHeight);
}

//neste caso aqui nos colocamos a imagem recortada como a imagem fixa pois eh a menor imagem
// que vera se a imagem parada e maior contem a menor e acabada de ser recortada
void PlayerStatus::compute(cv::Mat *src) {
  this->crop(src);
  this->result = this->compare(&this->playingStatusImg, this->img, this->threshold);
}

bool PlayerStatus::playing() {
  return bool(this->result);
}

void PlayerStatus::accept(AbstractVisitor &visitor) {
  return visitor.visit(*this);
}
