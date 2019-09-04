//
// Created by xima on 05/08/19.
//

#ifndef POKER_BOT_CALL_HPP
#define POKER_BOT_CALL_HPP

#include "../utils.hpp"
#include "../BaseClasses/BaseImage.hpp"
#include "../BaseClasses/BaseImageCompare.hpp"
#include "../AbstractClasses/AbstractVisitable.hpp"
#include "../AbstractClasses/AbstractVisitor.hpp"
#include "../BaseClasses/BaseMouse.hpp"
#include "../BaseClasses/BaseImageFindNumber.hpp"

class Call: public BaseImage, public BaseMouse, public BaseImageFindNumber, public AbstractVisitable {
private:
  const std::string pathCall = "/bet";
  constexpr const static Position callPosition = {1320, 965};
  const float threshold = 0.93;
  const size_t width = 235, height = 65;
  float result;
public:
  explicit Call();

  float size();
  void click();

  void compute(cv::Mat *src);
  void accept(AbstractVisitor& visitor) override ;
};
#endif //POKER_BOT_CALL_HPP
