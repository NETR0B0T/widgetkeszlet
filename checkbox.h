#ifndef CHECKBOX_H
#define CHECKBOX_H
#include "widget.h"
#include "graphics.hpp"
#include <functional>

class checkbox : public widget{
protected:
    int check;
public:
    checkbox(int pos_x , int pos_y);
    void rajzol() override;
    void event(genv::event ev) override;
    bool is_checked();
    std::function<void()>changed;
};

#endif // CHECKBOX_H
