//
// Created by xima on 31/07/19.
//

#ifndef POKER_BOT_POT_HPP
#define POKER_BOT_POT_HPP

#include "../BaseClasses/BaseImageFindNumber.hpp"
#include "../BaseClasses/BaseImage.hpp"
#include "../AbstractClasses/AbstractVisitable.hpp"
#include "../AbstractClasses/AbstractVisitor.hpp"
#include "../utils.hpp"


class Pot: public BaseImage, public BaseImageFindNumber, public AbstractVisitable {
private:
  const std::string pathPot = "/pot";
  constexpr const static Position potPosition = {878, 313};
  const float threshold = 0.90;
  const size_t width = 183, height = 40;
  float result;
public:
  explicit Pot();

  void compute(cv::Mat* src);

  float size();

  void accept(AbstractVisitor& visitor) override ;
};
#endif //POKER_BOT_POT_HPP
