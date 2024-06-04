#include "graphics.hpp"
#include "checkbox.h"
#include "widget.h"
#include <vector>
#include <string>
#include <iostream>
using namespace genv;
using namespace std;

checkbox::checkbox(int size_x, int size_y, int pos_x , int pos_y):widget(size_x, size_y, pos_x, pos_y), check(-1){}

void checkbox::rajzol(){
    gout << move_to(pos_x,pos_y) << color(255,255,255) << box(size_x, size_y) << move_to(pos_x+2,pos_y+2) << color(0,0,0) << box(size_x-4, size_y-4);
    if(check==1){
        gout << move_to(pos_x,pos_y) << color(255,255,255) <<line_to(pos_x+size_x,pos_y+size_y) << move_to(pos_x,pos_y+size_y) << line_to(pos_x+size_x,pos_y);
    }
}
void checkbox :: event(genv::event ev){
    int m_x= ev.pos_x;
    int m_y=ev.pos_y;
    if(ev.button == btn_left &&
            m_x > pos_x && m_x < pos_x+size_x && m_y > pos_y && m_y < pos_y+size_y){
        check*=-1;
    }
}
bool checkbox :: is_checked(){
    return check == -1 ? 0 : 1; //hehe Elvis operator :D
}
