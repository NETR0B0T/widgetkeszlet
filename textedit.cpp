#include "graphics.hpp"
#include "textedit.h"
#include "widget.h"
#include <vector>
#include <string>
#include <iostream>
using namespace genv;
using namespace std;

textedit::textedit(int pos_x , int pos_y):widget(200,30, pos_x, pos_y),szoveg(""){}

void textedit::rajzol(){
     if(gout.twidth(szoveg)<size_x){fs=30;gout << font("LiberationSans-Regular.ttf",20);}
    gout << move_to(pos_x,pos_y) << color(255,255,255) << box(size_x, size_y) << move_to(pos_x+2,pos_y+2) << color(100,100,100) << box(size_x-4, size_y-4);
    gout << color(255,255,255) << move_to(pos_x+6,pos_y+5) << text(szoveg);
}

string textedit::get_string(){
    return szoveg;
}

void textedit :: event(genv::event ev){
    if(ev.type==ev_key && ev.keycode>0 && ev.keycode<=255 && gout.twidth(szoveg)+gout.twidth("a")<size_x){
            if(ev.keycode>=32){
              szoveg+=ev.keycode;
            }
    }
    if(ev.keycode == key_backspace && szoveg.length()>0){
        szoveg.erase(szoveg.end()-1);
    }
}

void textedit::set_string(string a){
    szoveg = a;
}
