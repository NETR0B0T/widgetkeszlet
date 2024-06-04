#ifndef BUTTON_H
#define BUTTON_H
#include "widget.h"
#include <functional>

class button : public widget {

    std::string ertek;
public:

    button(int pos_x , int pos_y);
    void rajzol();
    void event(genv::event ev);
    std::function<void()>megnyom;
    void set_string(std::string a);
};
#endif // BUTTON_H
