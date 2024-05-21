#include "graphics.hpp"
#include "button.h"
#include "widget.h"
#include <iostream>
using namespace genv;
using namespace std;

button::button(int size_x, int size_y, int pos_x , int pos_y, int ertek): widget(size_x, size_y, pos_x, pos_y), ertek(ertek){}
void button::rajzol(){
    gout << move_to(pos_x, pos_y) << color(255,255,255) << box(size_x,size_y) << move_to(pos_x+size_x/2, pos_y+size_y/2)<< color(0,0,0) << text(to_string(ertek));
}
void button :: event(genv::event ev){

        int m_x =ev.pos_x;
        int m_y =ev.pos_y;
        if(m_x > pos_x && m_x < pos_x+size_x && m_y > pos_y && m_y < pos_y+size_y && ev.button ==-btn_left){
            ertek*=-1;
            cout << "ertek valt" << endl;}

    }


