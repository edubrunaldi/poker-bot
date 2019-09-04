//
// Created by xima on 02/08/19.
//

#include "../includes/ImageVisitor.hpp"

ImageVisitor::ImageVisitor(bool mocked) {
  this->mocked = mocked;
}

void ImageFromDisplay(std::vector<std::uint8_t>& Pixels, int& Width, int& Height, int& BitsPerPixel);


void ImageVisitor::takePicture() {
  if(this->mocked) {
    this->img = cv::imread("images/default/full-images/stack[.]pot[.]bet[.].png");
    return;
  }

  int Width = 0;
  int Height= 0;
  int Bpp = 0;
  ImageFromDisplay(Pixels, Width, Height, Bpp);

  if (Width && Height) {
    this->img = cv::Mat(Height, Width, Bpp > 24 ? CV_8UC4 : CV_8UC3, &this->Pixels[0]); //Mat(Size(Height, Width), Bpp > 24 ? CV_8UC4 : CV_8UC3, &Pixels[0]);
  }
  cv::Rect myROI(
          screenShotPosition[0],
          screenShotPosition[1],
          screenShotPosition[2],
          screenShotPosition[3]
  );

// Crop the full image to that image contained by the rectangle myROI
// Note that this doesn't copy the data
  this->img = ((this->img)(myROI));
}

void ImageVisitor::show() {
  cv::imshow("iii", this->img);
  cv::waitKey(0);
}

void ImageVisitor::visit(Table& table) {
//  if(this->mocked)
//    std::cout << "player visitor" << std::endl;
}

void ImageVisitor::visit(Player& player) {
//  if(this->mocked)
//    std::cout << "player visitor" << std::endl;
}

void ImageVisitor::visit(Card &card) {
  card.compute(&this->img);
//  if(this->mocked)
//    std::cout << "card visitor " << card.value() << std::endl;
}

void ImageVisitor::visit(Stack &stack) {
  stack.compute(&this->img);
//  if(this->mocked)
//    std::cout << "stack visitor " << stack.size() << std::endl;
}

void ImageVisitor::visit(PlayerStatus &playerStatus) {
  playerStatus.compute(&this->img);
//  if(this->mocked)
//    std::cout << "playerStatus visitor " << playerStatus.playing() << std::endl;
}

void ImageVisitor::visit(Dealer &dealer) {
  dealer.compute(&this->img);
//  if(this->mocked)
//    std::cout << "dealer visitor " << dealer.dealer() << std::endl;
}

void ImageVisitor::visit(Pot &pot) {
  pot.compute(&this->img);
//  if(this->mocked)
//    std::cout << "pot visitor " << pot.size() << std::endl;
}

void ImageVisitor::visit(Fold &fold) {
  fold.compute(&this->img);
//  if(this->mocked)
//    std::cout << "Fold visitor " << fold.active() << std::endl;
}

void ImageVisitor::visit(Call &call) {
  call.compute(&this->img);
//  if(this->mocked)
//    std::cout << "Call visitor " << call.size() << std::endl;
}

void ImageVisitor::visit(Bet &bet) {
  bet.compute(&this->img);
//  if(this->mocked)
//    std::cout << "Bet visitor " << bet.size() << std::endl;
}

void ImageVisitor::visit(CommunityCards &communityCards) {
//  if(this->mocked)
//    std::cout << "CommunityCards visitor " << std::endl;
}

/**
 * Caso de erro temos esses links:
 *  - https://www.imagemagick.org/Magick++/?fbclid=IwAR16ebnctiociT51sW4GARAx3fu1lH55NqVJLO0zFDNyrbVwNpcUorgXQ64
 *  - https://stackoverflow.com/questions/13219710/taking-a-screenshot-using-imagemagick-api
 * @param Pixels
 * @param Width
 * @param Height
 * @param BitsPerPixel
 */

void ImageFromDisplay(std::vector<std::uint8_t>& Pixels, int& Width, int& Height, int& BitsPerPixel)
{
  Display* display = XOpenDisplay(nullptr);
  Window root = DefaultRootWindow(display);

  XWindowAttributes attributes = {0};
  XGetWindowAttributes(display, root, &attributes);

  Width = attributes.width;
  Height = attributes.height;

  XImage* img = XGetImage(display, root, 0, 0 , Width, Height, AllPlanes, ZPixmap);
  BitsPerPixel = img->bits_per_pixel;
  Pixels.resize(Width * Height * 4);

  memcpy(&Pixels[0], img->data, Pixels.size());

  XDestroyImage(img);
  XCloseDisplay(display);
}
