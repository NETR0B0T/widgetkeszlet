#ifndef SZAMBEIRO_H
#define SZAMBEIRO_H

#include "widget.h"
//#include "graphics.hpp"

class szambeiro : public widget {

    int ertek;
public:

    void rajzol();
    szambeiro(int size_x, int size_y, int pos_x , int pos_y, int ertek);
        void event(genv::event ev);

 //  void futtat_szambeiro(szambeiro a);
};
#endif // SZAMBEIRO_H
