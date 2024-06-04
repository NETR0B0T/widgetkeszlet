#ifndef CHECKBOX_H
#define CHECKBOX_H
#include "widget.h"
#include "graphics.hpp"

class checkbox : public widget{
protected:
    int check;
public:
    checkbox(int size_x, int size_y, int pos_x , int pos_y);
    void rajzol() override;
    void event(genv::event ev) override;
    bool is_checked();
};

#endif // CHECKBOX_H
