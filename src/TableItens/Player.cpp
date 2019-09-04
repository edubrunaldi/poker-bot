//
// Created by xima on 07/07/19.
//

#include "../../includes/TableItens/Player.hpp"

Player::Player(PlayerPosition position, TableSize tableSize) {
  if (position == P0) {
    this->card1 = std::make_unique<Card>(Card(HAND_LEFT));
    this->card2 = std::make_unique<Card>(Card(HAND_RIGHT));
    this->stack = std::make_unique<Stack>(Stack());
  } else {
    this->playerStatus = std::make_unique<PlayerStatus>(PlayerStatus(position, tableSize));
  }
  this->dealer = std::make_unique<Dealer>(Dealer(position, tableSize));
}


std::string Player::handValue() {
  if (this->playerStatus != nullptr)
    return "";
  return this->card1->value() + this->card2->value();
}

bool Player::playing() {
  if (this->playerStatus == nullptr){
    std::cout << " Player = 0" << std::endl;
    return true;
  }

  return this->playerStatus->playing();
}

bool Player::isDealer() {
  return this->dealer->dealer();
}

float Player::stackSize() {
  return this->stack->size();
}

void Player::accept(AbstractVisitor& visitor) {
  if(this->card1 != nullptr) this->card1->accept(visitor);
  if(this->card2 != nullptr) this->card2->accept(visitor);
  if(this->dealer != nullptr) this->dealer->accept(visitor);
  if(this->playerStatus != nullptr) this->playerStatus->accept(visitor);
  if(this->stack != nullptr) this->stack->accept(visitor);
  return visitor.visit(*this);
}