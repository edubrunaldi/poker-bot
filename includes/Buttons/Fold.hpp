//
// Created by xima on 05/08/19.
//

#ifndef MINECRAFT2_3_FOLD_HPP
#define MINECRAFT2_3_FOLD_HPP

#include "../BaseClasses/BaseImage.hpp"
#include "../BaseClasses/BaseImageCompare.hpp"
#include "../AbstractClasses/AbstractVisitable.hpp"
#include "../AbstractClasses/AbstractVisitor.hpp"
#include "../BaseClasses/BaseMouse.hpp"
#include "../utils.hpp"

class Fold: public BaseImage, public BaseImageCompare, public BaseMouse, public AbstractVisitable {
private:
  constexpr const static Position foldPosition = {1000, 965};
  const float threshold = 0.90;
  const int width = 235;
  const int height = 65;
  std::unique_ptr<cv::Mat> foldImg;
  bool result;
public:
  explicit Fold();

  bool active();
  void click();

  void compute(cv::Mat *src);
  void accept(AbstractVisitor& visitor) override ;
};
#endif //MINECRAFT2_3_FOLD_HPP
