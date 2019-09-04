//
// Created by xima on 01/08/19.
//



#include <thread>
#include "../../includes/BaseClasses/BaseMouse.hpp"

BaseMouse::BaseMouse() {
  this->display = XOpenDisplay(0);
  this->root = DefaultRootWindow(this->display);
}

void BaseMouse::clickCoordinate(int x, int y, int width, int height) {
//  this->move(x, y);
  Position p = this->randPosition(width, height);
  this->move(p.x + x, p.y + y);
  int button = 1;
  Display* display = XOpenDisplay(NULL);
  XEvent event;

  if(display == NULL) {
    std::cout << "Nao foi possivel inicalizar o display em BaseMouse::click" << std::endl;
  }

  memset(&event, 0x00, sizeof(event));

  event.type = ButtonPress;
  event.xbutton.button = button;
  event.xbutton.same_screen = True;
  XQueryPointer(display, RootWindow(display, DefaultScreen(display)), &event.xbutton.root, &event.xbutton.window, &event.xbutton.x_root, &event.xbutton.y_root, &event.xbutton.x, &event.xbutton.y, &event.xbutton.state);
  event.xbutton.subwindow = event.xbutton.window;

  while(event.xbutton.subwindow) {
    event.xbutton.window = event.xbutton.subwindow;
    XQueryPointer(display, event.xbutton.window, &event.xbutton.root, &event.xbutton.subwindow, &event.xbutton.x_root, &event.xbutton.y_root, &event.xbutton.x, &event.xbutton.y, &event.xbutton.state);
  }
  if(XSendEvent(display, PointerWindow, True, 0xfff, &event) == 0) {
    std::cout << "Erro: " << stderr << std::endl;
  }
  XFlush(display);
//  usleep(2000000);
  std::this_thread::sleep_for(std::chrono::seconds(2));
  event.type = ButtonRelease;
  event.xbutton.state = 0x100;
  if(XSendEvent(display, PointerWindow, True, 0xfff, &event) == 0) {
    std::cout << "Erro: " << stderr << std::endl;
  }
  XFlush(display);
  XCloseDisplay(display);
}

void BaseMouse::move(int x, int y) {
  XWarpPointer(display, None, root, 0, 0, 0, 0, x, y);
  XFlush(this->display);
}

void BaseMouse::move(Position p, int x, int y) {
  XWarpPointer(display, None, root, 0, 0, x, y, p.x, p.y);
  XFlush(this->display);
}

Position BaseMouse::randPosition(int width, int height) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(0, width-1);
  Position p = Position();
  p.x = dist(mt);
  p.y = dist(mt);
  return p;
}
