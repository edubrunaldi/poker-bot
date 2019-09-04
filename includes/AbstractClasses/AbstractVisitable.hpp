//Visitor
// Created by xima on 02/08/19.
//

#ifndef POKER_BOT_ABSTRACTVISITABLE_HPP
#define POKER_BOT_ABSTRACTVISITABLE_HPP


class AbstractVisitor;

class AbstractVisitable {
public:
  virtual void accept(AbstractVisitor& visitor) = 0;
};
#endif //POKER_BOT_ABSTRACTVISITABLE_HPP
