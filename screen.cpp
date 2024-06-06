#include "graphics.hpp"
#include "screen.h"
#include "widget.h"
#include <vector>
#include <string>
#include <iostream>
using namespace genv;
using namespace std;

screen::screen(int pos_x , int pos_y):widget(350,30, pos_x, pos_y),szoveg(""){}

void screen::rajzol(){
  gout << font("LiberationSans-Regular.ttf",20);
    gout << move_to(pos_x,pos_y) << color(255,255,255) << box(size_x, size_y) << move_to(pos_x+2,pos_y+2) << color(100,100,100) << box(size_x-4, size_y-4);
    gout << color(255,255,255) << move_to(pos_x+6,pos_y+5) << text(szoveg);
}

void screen:: set_string(string a){
    if(gout.twidth(a)<size_x){
    szoveg = a;}
}

void screen:: add_string(string a){
   if(gout.twidth(szoveg+a)<size_x){
    szoveg += a;}
}

void screen :: event(genv::event ev){}
