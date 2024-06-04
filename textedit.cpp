#include "graphics.hpp"
#include "textedit.h"
#include "widget.h"
#include <vector>
#include <string>
#include <iostream>
using namespace genv;
using namespace std;

textedit::textedit(int size_x, int size_y, int pos_x , int pos_y):widget(size_x, size_y, pos_x, pos_y),szoveg(""){}

void textedit::rajzol(){
    gout << move_to(pos_x,pos_y) << color(255,255,255) << box(size_x, size_y) << move_to(pos_x+2,pos_y+2) << color(0,0,0) << box(size_x-4, size_y-4);
    gout << color(255,255,255) << move_to(pos_x+6,pos_y+5) << text(szoveg);
}

string textedit::get_string(){
    return szoveg;
}

void textedit :: event(genv::event ev){
    if(ev.type==ev_key && ev.keycode>0 && ev.keycode<=255 && gout.twidth(szoveg) < size_x-gout.twidth("a")){
            if(ev.keycode>=32){
              szoveg+=ev.keycode;
            }
    }
    if(ev.keycode == key_backspace && szoveg.length()>0){
        szoveg.erase(szoveg.end()-1);
    }
}
