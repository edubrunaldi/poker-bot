//
// Created by xima on 07/07/19.
//

#ifndef MINECRAFT2_3_CARD_HPP
#define MINECRAFT2_3_CARD_HPP

#include "../BaseClasses/BaseImage.hpp"
#include "../utils.hpp"
#include "../BaseClasses/BaseImageCompare.hpp"
#include "../AbstractClasses/AbstractVisitable.hpp"
#include "../AbstractClasses/AbstractVisitor.hpp"

enum PositionCardsEnum { HAND_LEFT, HAND_RIGHT, FLOP_ONE, FLOP_TWO, FLOP_THREE, TURN, RIVER};
static std::string pathHand = "/hand-cards";
static std::string pathCommunity = "/community-cards";

struct Suit {
  std::string suitName;
  cv::Mat suit;
};

enum TypeCardEnum {
  HAND,
  COMMUNITY,
};

struct Rank {
  std::string rankName;
  cv::Mat rank;
};

class Card : public BaseImage, public BaseImageCompare, public AbstractVisitable {
private:

  constexpr const static Position cardsPosition[7] = { {870, 656}, {962, 656}, {712, 357}, {813, 357}, {914, 357}, {1015, 357}, {1116, 357} };
  size_t typeCard;
  const float threshold = 0.90;
  const size_t width = 30, height = 70;
  static std::vector<Suit> suitsHand;
  static std::vector<Rank> ranksHand;
  static std::vector<Suit> suitsCommunity;
  static std::vector<Rank> ranksCommunity;
  std::string result;
public:
  explicit Card(PositionCardsEnum cardPosition);

  std::string value();
  void compute(cv::Mat *original);
  void accept(AbstractVisitor& visitor) override ;
};

#endif //MINECRAFT2_3_CARD_HPP
