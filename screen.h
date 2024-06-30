#ifndef SCREEN_H
#define SCREEN_H
#include "widget.h"

class screen : public widget{
protected:
    std::string szoveg;
    int fs;
public:
    screen(int pos_x, int pos_y);
    void rajzol();
    void set_string(std::string a);
    void add_string(std::string a);
    std::string get_string();
    void event(genv::event ev);
};

#endif // SCREEN_H
