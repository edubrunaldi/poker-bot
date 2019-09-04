//
// Created by xima on 07/07/19.
//

#ifndef MINECRAFT2_3_PLAYER_HPP
#define MINECRAFT2_3_PLAYER_HPP

#include "../BaseClasses/BaseImage.hpp"
#include "Card.hpp"
#include "../PlayerItens/PlayerStatus.hpp"
#include "../utils.hpp"
#include "../PlayerItens/Dealer.hpp"
#include "../PlayerItens/Stack.hpp"
#include "../AbstractClasses/AbstractVisitable.hpp"
#include "../AbstractClasses/AbstractVisitor.hpp"
#include "Table.hpp"

class Player: public AbstractVisitable {
private:
  std::unique_ptr<Card> card1;
  std::unique_ptr<Card> card2;
  std::unique_ptr<PlayerStatus> playerStatus;
  std::unique_ptr<Dealer> dealer;
  std::unique_ptr<Stack> stack;
public:

  explicit Player(PlayerPosition position, TableSize tableSize);

  std::string handValue();
  bool playing();
  bool isDealer();
  float stackSize();

  void accept(AbstractVisitor& visitor) override ;
};

#endif //MINECRAFT2_3_PLAYER_HPP
