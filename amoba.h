#ifndef AMOBA_H
#define AMOBA_H
#include "widget.h"
#include <vector>

class amoba : public widget{
    int seg;
    int turn=1;
    int w =5;
    int gameover=0;
    std::vector<std::vector<int>>v;
public:
    void rajzol();
    amoba(int size_x, int size_y, int pos_x , int pos_y, int seg);
        void event(genv::event ev);
    bool ellenoriz(int x, int y, int turn);
    bool betelt();

};
#endif // AMOBA_H
