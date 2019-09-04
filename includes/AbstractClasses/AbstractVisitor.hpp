//
// Created by xima on 02/08/19.
//

#ifndef POKER_BOT_ABSTRACTVISITOR_HPP
#define POKER_BOT_ABSTRACTVISITOR_HPP

class Table;
class Pot;
class Player;
class Card;
class Stack;
class PlayerStatus;
class Dealer;
class Fold;
class Call;
class Bet;
class CommunityCards;

class AbstractVisitor {
public:
  virtual void visit(Table& table) = 0;
  virtual void visit(Pot& pot) = 0;
  virtual void visit(Player& player) = 0;
  virtual void visit(Card& card) = 0;
  virtual void visit(Stack& stack) = 0;
  virtual void visit(PlayerStatus& playerStatus) = 0;
  virtual void visit(Dealer& dealer) = 0;
  virtual void visit(Fold& fold) = 0;
  virtual void visit(Call& call) = 0;
  virtual void visit(Bet& bet) = 0;
  virtual void visit(CommunityCards& communityCards) = 0;
};
#endif //POKER_BOT_ABSTRACTVISITOR_HPP
