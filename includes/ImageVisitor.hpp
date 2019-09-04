//
// Created by xima on 02/08/19.
//

#ifndef MINECRAFT2_3_IMAGEVISITOR_HPP
#define MINECRAFT2_3_IMAGEVISITOR_HPP

#include <iostream>
#include "AbstractClasses/AbstractVisitor.hpp"
#include "opencv4/opencv2/highgui.hpp"
#include "TableItens/Pot.hpp"
#include "TableItens/Card.hpp"
#include "PlayerItens/Dealer.hpp"
#include "PlayerItens/PlayerStatus.hpp"
#include "TableItens/Pot.hpp"
#include "PlayerItens/Stack.hpp"
#include "Buttons/Fold.hpp"
#include "Buttons/Call.hpp"
#include "Buttons/Bet.hpp"
#include "TableItens/CommunityCards.hpp"
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "opencv4/opencv2/highgui.hpp"
#include "utils.hpp"

//static int screenShotPosition[4] = {0, 0, 1920, 1080};

class ImageVisitor: public AbstractVisitor {
private:
  cv::Mat img;
  std::vector<std::uint8_t> Pixels;
  bool mocked;
//  ScreenShot screenShot;
public:
  explicit  ImageVisitor(bool mocked);
//  ~ImageVisitor();
  void takePicture();
  void show();
  void visit(Table& table) override ;
  void visit(Player& player) override ;
  void visit(Card& card) override ;
  void visit(Stack& stack) override ;
  void visit(PlayerStatus& playerStatus) override ;
  void visit(Dealer& dealer) override ;
  void visit(Pot& pot) override ;
  void visit(Fold& fold) override ;
  void visit(Call& call) override ;
  void visit(Bet& bet) override ;
  void visit(CommunityCards& communityCards) override ;

};
#endif //MINECRAFT2_3_IMAGEVISITOR_HPP
