//#ifndef WIDGET_H
//#define WIDGET_H

#pragma once


#include <vector>
#include <string>
#include "graphics.hpp"

class widget {
 protected:
    int size_x, size_y, pos_x , pos_y;
 public:
 //widget(int x, int y): pos_x(x), pos_y(y){};
    widget(int size_x, int size_y, int pos_x , int pos_y);
 virtual void rajzol()=0;

 virtual bool active(int m_x, int m_y);

 virtual void event(genv::event ev)=0;
};


//#endif // WIDGET_H
