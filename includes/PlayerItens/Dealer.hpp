//
// Created by xima on 30/07/19.
//

#ifndef MINECRAFT2_3_DEALER_HPP
#define MINECRAFT2_3_DEALER_HPP

#include "../utils.hpp"
#include "../BaseClasses/BaseImage.hpp"
#include "../BaseClasses/BaseImageCompare.hpp"
#include "../AbstractClasses/AbstractVisitable.hpp"
#include "../AbstractClasses/AbstractVisitor.hpp"
#include "../TableItens/Table.hpp"

class Dealer: public BaseImage, public BaseImageCompare, public AbstractVisitable {
private:
  const std::string pathDealers = "/dealer";
  //TODO criar posicoes para mesa de 2, 3 e 6 posicoes
  constexpr const static Position dealerPosition[9] = {{813, 644}, {579, 522}, {489, 377}, {655, 284}, {890, 218}, {1182, 245}, {1336, 322}, {1381, 518}, {1210, 593}};
  const float threshold = 0.90;
  const size_t width = 47, height = 40;
  cv::Mat dealerImg;
  bool result;
public:
  explicit Dealer(PlayerPosition playerPosition, TableSize tableSize);
//  bool dealer(cv::Mat *src);
  void compute(cv::Mat *src);
  bool dealer();
  void accept(AbstractVisitor& visitor) override ;
};
#endif //MINECRAFT2_3_DEALER_HPP
