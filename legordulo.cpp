#include "graphics.hpp"
#include "legordulo.h"
#include "widget.h"
#include <vector>
#include <string>
#include <iostream>
using namespace genv;
using namespace std;


legordulo ::legordulo(int pos_x , int pos_y):widget(200,150, pos_x, pos_y), shift(0), kivalasztott(-1){};
void legordulo :: rajzol(){
    gout //<< move_to(pos_x, pos_y) << color(255,255,255) << box(size_x,size_y)
         //<< color(0,0,0) << move_to(pos_x+3,pos_y+3) <<box(size_x-6,size_y-6)
         << color(255,255,255) << move_to(pos_x+10,pos_y+10) << box(size_x-20, size_y-20);
            for(int i=0; i<4 ; i++){
                gout << color(100,100,100) << move_to(pos_x+15,pos_y+15+i*((size_y-25)/4)) << box(size_x-30, (size_y-30)/4);
            }
            for (unsigned int i=0; i<v.size(); i++){
               if(i<4){
                gout <<move_to(pos_x+size_x/3,pos_y+15+i*((size_y-25)/4)+5); //szöveg helye
               gout << color(255,255,255);
                    if(v.size()>4){             //csak akkor shiftelunk, ha van hova
                        if(i+shift == kivalasztott){gout << color(255,0,0);}
                        gout<<text(v[i+shift]);
                    }else{
                       if(i == kivalasztott){gout << color(255,0,0);}
                        gout<<text(v[i]);}       //amugy csak kiirunk
               }
            }
         //gout<< refresh;
}
string legordulo :: get_indexed(int i){
    return v[i];
}

void legordulo :: set_shift(int a, int m_x, int m_y){
    if(m_x > pos_x && m_x < pos_x+size_x && m_y >pos_y && m_y < pos_y+ size_y && shift+a >=0 && shift+a < v.size()){
        if(v.size()>4 && shift+ a <= v.size()-4){
        shift +=a;}
    }

}

void legordulo :: push_string(string a){
    if (a.size()>0)
    v.push_back(a);
}

void legordulo :: push_int(int a){
    v.push_back(to_string(a));
}

string legordulo :: get_kivalasztott(){
    return v[kivalasztott];
}

void legordulo :: erase_kivalasztott(){
    if(v.size()>0 && kivalasztott !=-1)
    v.erase(v.begin()+kivalasztott);
    kivalasztott = -1;
}

int legordulo :: list_size(){
    return v.size();
}

void legordulo :: kattintas(int m_x, int m_y){
      if(m_x > pos_x+15 && m_y > pos_y+15+0*((size_y-25)/4) && m_x < pos_x+15 + size_x-30 && m_y < pos_y+15+0*((size_y-25)/4)+(size_y-30)/4 && v.size()>=1){
          kivalasztott= 0+shift;
          cout << v[kivalasztott];
      }
      if(m_x > pos_x+15 && m_y > pos_y+15+1*((size_y-25)/4) && m_x < pos_x+15 + size_x-30 && m_y < pos_y+15+1*((size_y-25)/4)+(size_y-30)/4 && v.size()>=2){
          kivalasztott= 1+shift;
          cout << v[kivalasztott];
      }
      if(m_x > pos_x+15 && m_y > pos_y+15+2*((size_y-25)/4) && m_x < pos_x+15 + size_x-30 && m_y < pos_y+15+2*((size_y-25)/4)+(size_y-30)/4 && v.size()>=3){
          kivalasztott= 2+shift;
          cout << v[kivalasztott];
      }
      if(m_x > pos_x+15 && m_y > pos_y+15+3*((size_y-25)/4) && m_x < pos_x+15 + size_x-30 && m_y < pos_y+15+3*((size_y-25)/4)+(size_y-30)/4 && v.size()>=4){
          kivalasztott= 3+shift;
          cout << v[kivalasztott];
      }


}

void legordulo :: event(genv::event ev){
    int m_x;
    int m_y;
    if(ev.button == -btn_left){
          m_x= ev.pos_x;
          m_y =ev.pos_y;
          legordulo::kattintas(m_x, m_y);

    }
    if(ev.button == btn_wheelup){
        m_x= ev.pos_x;
        m_y =ev.pos_y;
        legordulo::set_shift(1, m_x, m_y);
    }
    if(ev.button == btn_wheeldown){
        m_x= ev.pos_x;
        m_y =ev.pos_y;
        legordulo::set_shift(-1, m_x, m_y);
        rajzol();

    }
}
