#ifndef BUTTON_H
#define BUTTON_H
#include "widget.h"
#include <functional>

class button : public widget {

    int ertek;
public:
    void rajzol();
    button(int size_x, int size_y, int pos_x , int pos_y, int ertek);
        void event(genv::event ev);
        std::function<void()>megynyom;

 //  void futtat_szambeiro(szambeiro a);
};
#endif // BUTTON_H
