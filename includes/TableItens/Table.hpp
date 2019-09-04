//
// Created by xima on 02/08/19.
//

#ifndef MINECRAFT2_3_TABLE_HPP
#define MINECRAFT2_3_TABLE_HPP

#include "Pot.hpp"
#include "Player.hpp"
#include "../Buttons/Fold.hpp"
#include "../Buttons/Call.hpp"
#include "../Buttons/Bet.hpp"
#include "../Buttons/RaiseButton.hpp"
#include "CommunityCards.hpp"

//enum TableSize { MAX_2, MAX_3, MAX_6, MAX_9 };
//enum StreetEnum  {PRE_FLOP_STREET, FLOP_STREET, TURN_STREET, RIVER_STREET};
//enum Actions {FOLD_ACTION, CALL_ACTION, RAISE_BUTTON_1_ACTION, RAISE_BUTTON_2_ACTION, RAISE_BUTTON_3_ACTION, RAISE_BUTTON_4_ACTION};


class Table: public AbstractVisitable {
private:
  std::unique_ptr<Pot> pot;
  std::unique_ptr<Player> user;
  std::unique_ptr<std::vector<std::unique_ptr<Player>>> players;
  std::unique_ptr<Fold> fold;
  std::unique_ptr<Call> call;
  std::unique_ptr<Bet> bet;
  std::unique_ptr<std::vector<std::unique_ptr<RaiseButton>>> raiseButtons;
  std::unique_ptr<CommunityCards> communityCards;
  float bigBlind;
  TableSize tableSize;
public:
  explicit Table(TableSize totalPlayers);
  void accept(AbstractVisitor& visitor) override ;
  void setBigBlind(float bigBlind);
  bool foldActive();
  void makeAction(Actions action);
  StreetEnum getStreet();
  std::string getHand();
  float getBigBlind();
  std::string getCommunityCards();
  int getDealerPosition();
  TableSize sizeTable();
  float getCallSize();
  float getBetSize();
  float getStackSize();
  float getPotSize();
  std::string playersPlaying();

};
#endif //MINECRAFT2_3_TABLE_HPP
