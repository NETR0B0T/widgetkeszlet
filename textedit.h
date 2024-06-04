#ifndef TEXTEDIT_H
#define TEXTEDIT_H
#include "widget.h"
#include <string>
#include "graphics.hpp"

class textedit : public widget{
protected:
    std::string szoveg;
public:
    textedit(int pos_x , int pos_y);
    void rajzol() override;
    std::string get_string();
    void event(genv::event ev) override;
};

#endif // TEXTEDIT_H
