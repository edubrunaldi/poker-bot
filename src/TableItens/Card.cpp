//
// Created by xima on 07/07/19.
//

#include "../../includes/TableItens/Card.hpp"

std::vector<Suit> Card::suitsHand = {
  {"d", cv::imread(pathCommonsImages + pathHand + "/diamond.png")},
  {"h", cv::imread(pathCommonsImages + pathHand + "/heart.png")},
  {"c", cv::imread(pathCommonsImages + pathHand + "/club.png")},
  {"s", cv::imread(pathCommonsImages + pathHand + "/spade.png")}};

std::vector<Rank> Card::ranksHand = {
  {"2", cv::imread(pathCommonsImages + pathHand + "/2.png")},
  {"3", cv::imread(pathCommonsImages + pathHand + "/3.png")},
  {"4", cv::imread(pathCommonsImages + pathHand + "/4.png")},
  {"5", cv::imread(pathCommonsImages + pathHand + "/5.png")},
  {"6", cv::imread(pathCommonsImages + pathHand + "/6.png")},
  {"7", cv::imread(pathCommonsImages + pathHand + "/7.png")},
  {"8", cv::imread(pathCommonsImages + pathHand + "/8.png")},
  {"9", cv::imread(pathCommonsImages + pathHand + "/9.png")},
  {"t", cv::imread(pathCommonsImages + pathHand + "/t.png")},
  {"j", cv::imread(pathCommonsImages + pathHand + "/j.png")},
  {"q", cv::imread(pathCommonsImages + pathHand + "/q.png")},
  {"k", cv::imread(pathCommonsImages + pathHand + "/k.png")},
  {"a", cv::imread(pathCommonsImages + pathHand + "/a.png")}};

std::vector<Suit> Card::suitsCommunity = {
  {"d", cv::imread(pathCommonsImages + pathCommunity + "/diamond.png")},
  {"h", cv::imread(pathCommonsImages + pathCommunity + "/heart.png")},
  {"c", cv::imread(pathCommonsImages + pathCommunity + "/club.png")},
  {"s", cv::imread(pathCommonsImages + pathCommunity + "/spade.png")}};

std::vector<Rank> Card::ranksCommunity = {
  {"2", cv::imread(pathCommonsImages + pathCommunity + "/2.png")},
  {"3", cv::imread(pathCommonsImages + pathCommunity + "/3.png")},
  {"4", cv::imread(pathCommonsImages + pathCommunity + "/4.png")},
  {"5", cv::imread(pathCommonsImages + pathCommunity + "/5.png")},
  {"6", cv::imread(pathCommonsImages + pathCommunity + "/6.png")},
  {"7", cv::imread(pathCommonsImages + pathCommunity + "/7.png")},
  {"8", cv::imread(pathCommonsImages + pathCommunity + "/8.png")},
  {"9", cv::imread(pathCommonsImages + pathCommunity + "/9.png")},
  {"t", cv::imread(pathCommonsImages + pathCommunity + "/t.png")},
  {"j", cv::imread(pathCommonsImages + pathCommunity + "/j.png")},
  {"q", cv::imread(pathCommonsImages + pathCommunity + "/q.png")},
  {"k", cv::imread(pathCommonsImages + pathCommunity + "/k.png")},
  {"a", cv::imread(pathCommonsImages + pathCommunity + "/a.png")}};

/**
 *
 */
Card::Card(PositionCardsEnum cardPosition) : BaseImage(), BaseImageCompare() {
  this->result = "";
  this->typeCard = cardPosition == HAND_LEFT || cardPosition == HAND_RIGHT ? HAND : COMMUNITY;
  this->imgPosition = std::make_unique<ImageCoordinate>(ImageCoordinate());
  this->imgPosition->x = Card::convertCropSizeToScreenSize(Card::cardsPosition[cardPosition].x, pointX);
  this->imgPosition->y = Card::convertCropSizeToScreenSize(Card::cardsPosition[cardPosition].y, pointY);
  this->imgPosition->width = Card::convertCropSizeToScreenSize(width, imgWidth);
  this->imgPosition->height = Card::convertCropSizeToScreenSize(height, imgHeight);
}

void Card::compute(cv::Mat *original) {
  this->crop(original);

  std::vector<Suit> *suites = this->typeCard == HAND ? &Card::suitsHand : &Card::suitsCommunity;
  std::vector<Rank> *ranks = this->typeCard == HAND ? &Card::ranksHand : &Card::ranksCommunity;

  for (Suit suit: *suites) {
    if (this->compare(&(suit.suit), this->img, this->threshold)) {
      for(Rank rank: *ranks) {
        if (this->compare(&(rank.rank), this->img, this->threshold)) {
          this->result = rank.rankName + suit.suitName;
          return;
        }
      }
    }
  }
  this->result = "";
}

std::string Card::value() {
  return std::string(this->result);
}

void Card::accept(AbstractVisitor &visitor) {
  return visitor.visit(*this);
}
