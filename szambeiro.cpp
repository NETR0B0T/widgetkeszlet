#include "graphics.hpp"
#include "szambeiro.h"
#include "widget.h"
#include <iostream>
using namespace genv;
using namespace std;

szambeiro ::szambeiro(int pos_x , int pos_y): widget(100,40, pos_x, pos_y), ertek(0){}
//szambeiro ::szambeiro(int size_x, int size_y, int pos_x , int pos_y): widget(size_x, size_y, pos_x, pos_y), ertek(0){}

void szambeiro :: rajzol(){
    size_x= gout.twidth(to_string(ertek))+100;
     gout << font("LiberationSans-Regular.ttf",20);
    gout << move_to(pos_x,pos_y) << color(255,255,255) << box(size_x,size_y)
         << color(100,100,100) << move_to(pos_x+3,pos_y+3) <<box(size_x-6,size_y-6)
         << move_to(size_x/8+pos_x,size_y/5+pos_y) << color(255,255,255)<< text(to_string(ertek))   //doboz
         << move_to(size_x/4*3+pos_x,pos_y) << box(size_x/4,size_y/2)       //felsonyil
         << color(100,100,100)
         << move_to(size_x/4*3+pos_x+3,pos_y+3) << box(size_x/4-6,size_y/2-6)
         << color(255,255,255)
         << move_to(size_x/4*3+pos_x,size_y/2+pos_y) << box(size_x/4,size_y/2)
         << color(100,100,100)
         << move_to(size_x/4*3+pos_x+3,size_y/2+pos_y+3) << box(size_x/4-6,size_y/2-6); //alsonyil
         }
int szambeiro :: get_int(){
    return ertek;
}

void szambeiro :: event(genv::event ev){
    int m_x= ev.pos_x;
    int m_y=ev.pos_y;
    if(ev.button == btn_left){
        if(m_x > size_x/4*3+pos_x && m_x < size_x/4*3+pos_x+size_x/4 && m_y > pos_y && m_y < size_y/2+pos_y){
            ertek++;
        }
        if(m_x > size_x/4*3+pos_x && m_x < size_x/4*3+pos_x+size_x/4 && m_y > size_y/2+pos_y+3 && m_y < size_y+pos_y){
            ertek--;
        }
    }
    if(ev.keycode == key_pgup){
            ertek+=100;
       }
    if(ev.keycode == key_pgdn){
            ertek-=100;
       }
}
