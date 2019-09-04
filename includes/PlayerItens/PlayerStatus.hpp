//
// Created by xima on 27/07/19.
//

#ifndef MINECRAFT2_3_PLAYERSTATUS_HPP
#define MINECRAFT2_3_PLAYERSTATUS_HPP

#include "../BaseClasses/BaseImage.hpp"
#include "../utils.hpp"
#include "../BaseClasses/BaseImageCompare.hpp"
#include "../AbstractClasses/AbstractVisitable.hpp"
#include "../AbstractClasses/AbstractVisitor.hpp"
#include "../TableItens/Table.hpp"

class PlayerStatus : public BaseImage, public BaseImageCompare, public AbstractVisitable {
private:
  const std::string pathPlayerStatus = "/playing";
  //TODO criar posicoes para mesa de 2, 3 e 6 players
  constexpr const static Position playersPositions[8] = { {429, 588}, {283, 377}, {345, 173}, {618, 72}, {1108, 73}, {1381, 173}, {1443, 376}, {1294, 587} };
  const float threshold = 0.90;
  const size_t width = 195, height = 35;
  cv::Mat playingStatusImg;
  bool result;
public:
  explicit PlayerStatus(PlayerPosition, TableSize tableSize);

  void compute(cv::Mat *src);

  bool playing();

  void accept(AbstractVisitor& visitor) override ;
};

#endif //MINECRAFT2_3_PLAYERSTATUS_HPP
