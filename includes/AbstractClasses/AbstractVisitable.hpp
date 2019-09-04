//Visitor
// Created by xima on 02/08/19.
//

#ifndef MINECRAFT2_3_ABSTRACTVISITABLE_HPP
#define MINECRAFT2_3_ABSTRACTVISITABLE_HPP


class AbstractVisitor;

class AbstractVisitable {
public:
  virtual void accept(AbstractVisitor& visitor) = 0;
};
#endif //MINECRAFT2_3_ABSTRACTVISITABLE_HPP
