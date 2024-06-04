#ifndef SZAMBEIRO_H
#define SZAMBEIRO_H

#include "widget.h"
//#include "graphics.hpp"

class szambeiro : public widget {

    int ertek;
public:
   // szambeiro(int size_x, int size_y, int pos_x , int pos_y);
    szambeiro(int size_x, int size_y, int pos_x , int pos_y);
    void rajzol();
    void event(genv::event ev);
    int get_int();

};
#endif // SZAMBEIRO_H
