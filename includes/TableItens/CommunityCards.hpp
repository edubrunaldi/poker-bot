//
// Created by xima on 07/08/19.
//

#ifndef MINECRAFT2_3_COMMUNITYCARDS_HPP
#define MINECRAFT2_3_COMMUNITYCARDS_HPP

#include <bits/unique_ptr.h>
#include "Card.hpp"
#include "../AbstractClasses/AbstractVisitable.hpp"
#include "../AbstractClasses/AbstractVisitor.hpp"

class CommunityCards: public AbstractVisitable {
private:
  std::unique_ptr<std::vector<std::unique_ptr<Card>>> cards;
public:
  CommunityCards();
  void accept(AbstractVisitor &visitor) override ;
  int cardOnTable();
  std::string getCards();
};
#endif //MINECRAFT2_3_COMMUNITYCARDS_HPP
