//
// Created by xima on 05/08/19.
//

#ifndef POKER_BOT_BET_HPP
#define POKER_BOT_BET_HPP


#include "../BaseClasses/BaseImage.hpp"
#include "../BaseClasses/BaseMouse.hpp"
#include "../AbstractClasses/AbstractVisitable.hpp"
#include "../AbstractClasses/AbstractVisitor.hpp"
#include "../BaseClasses/BaseImageFindNumber.hpp"
#include "../utils.hpp"

class Bet: public BaseImage, public BaseMouse, public BaseImageFindNumber, public AbstractVisitable {
private:
  const std::string pathBet = "/bet";
  constexpr const static Position betPosition = {1640, 965};
  const float threshold = 0.90;
  const size_t width = 235, height = 65;
  float result;
public:
  explicit Bet();

  float size();
  void click();
  void compute(cv::Mat *src);
  void accept(AbstractVisitor& visitor) override ;
};

#endif //POKER_BOT_BET_HPP
