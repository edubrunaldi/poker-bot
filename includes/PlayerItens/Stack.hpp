//
// Created by xima on 30/07/19.
//

#ifndef MINECRAFT2_3_STACK_HPP
#define MINECRAFT2_3_STACK_HPP

#include "../utils.hpp"
#include "../BaseClasses/BaseImage.hpp"
#include "../BaseClasses/BaseImageCompare.hpp"
#include "../AbstractClasses/AbstractVisitable.hpp"
#include "../AbstractClasses/AbstractVisitor.hpp"
#include "../BaseClasses/BaseImageFindNumber.hpp"

class Stack: public BaseImage, public BaseImageFindNumber, public AbstractVisitable {
private:
  const std::string pathStack = "/stack";
  constexpr const static Position stackPosition = {827, 774};
  const float threshold = 0.90;
  const size_t width = 181, height = 45;
  float result;
public:
  explicit Stack();

  void compute(cv::Mat* src);
  float size();
  void accept(AbstractVisitor& visitor) override ;
};

#endif //MINECRAFT2_3_STACK_HPP
