//
// Created by xima on 07/08/19.
//

#include "../../includes/TableItens/CommunityCards.hpp"

CommunityCards::CommunityCards() {
  this->cards = std::make_unique<std::vector<std::unique_ptr<Card>>>(std::vector<std::unique_ptr<Card>>());
  this->cards->push_back(std::make_unique<Card>(Card(FLOP_ONE)));
  this->cards->push_back(std::make_unique<Card>(Card(FLOP_TWO)));
  this->cards->push_back(std::make_unique<Card>(Card(FLOP_THREE)));
  this->cards->push_back(std::make_unique<Card>(Card(TURN)));
  this->cards->push_back(std::make_unique<Card>(Card(RIVER)));
}

void CommunityCards::accept(AbstractVisitor &visitor) {
  for(const auto &card: *this->cards) {
      card->accept(visitor);
  }
  return visitor.visit(*this);
}


int CommunityCards::cardOnTable() {
  int count = 0;
  for(const auto &card: *this->cards) {
    if(!card->value().empty())
      ++count;
  }
  return count;
}

std::string CommunityCards::getCards() {
  std::string cardsShowed;
  for(const auto &card: *this->cards) {
    cardsShowed += card->value();
  }
  return cardsShowed;
}
