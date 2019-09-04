////
//// Created by xima on 04/08/19.
////
//
//#include "../includes/ScreenShot.hpp"
//
////ScreenShot::ScreenShot() {
////  this->display = XOpenDisplay(NULL);
////  this->root = DefaultRootWindow(display);
////
////}
//
//cv::Mat *ScreenShot::take(int x, int y, int width, int height) {
//  this->display = XOpenDisplay(nullptr);
//  int screen = DefaultScreen(this->display);
//  Window root = RootWindow(this->display, screen);
//  this->img = nullptr;
//  unsigned int aa = 100;
//  unsigned int bb = 100;
//  this->img = XGetImage(this->display, root, x, y, width, height, AllPlanes, ZPixmap);
//
//  auto *cvImg = new cv::Mat();
//  *cvImg = cv::Mat(width, height, CV_8UC4, this->img->data);
////  cv::Mat *result = new cv::Mat(cvImg.clone());
////  *cvImg = cv::Mat(height, width, CV_8UC4, this->img->data);
//
//  return cvImg;
//}
//
//void ScreenShot::closeDisplay() {
//  XCloseDisplay(this->display);
//  XDestroyImage(this->img);
//}
////
////ScreenShot::~ScreenShot() {
////  XCloseDisplay(this->display);
////  if(this->img != nullptr)
////    XDestroyImage(this->img);
////}