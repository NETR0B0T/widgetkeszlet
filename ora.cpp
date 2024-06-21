#include "graphics.hpp"
#include "ora.h"
#include "widget.h"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
using namespace genv;
using namespace std;

ora::ora(int pos_x, int pos_y):widget(200,200, pos_x, pos_y), hour(0), min(0), hour_deg(0), min_deg(0){};

void ora :: rajzol(){

    min_deg=(min/60)*2*pi-pi/2;


    if (hour<=12){
    hour_deg=hour*(2*pi)/12-(pi/2)+min/60*pi/6;}
    else{hour_deg=(hour-12)*(2*pi)/12-pi/2;}

    gout << move_to(pos_x, pos_y);
        int r= size_x/2;
    for(int y=0; y<= size_y; y++){for(int x=0; x<= size_x; x++){
            if((((r-x)*(r-x)+(r-y)*(r-y))<=r*r)){
            gout << move_to(pos_x+x,pos_y+y) << color(100,100,100) << dot;}else if((((r-x)*(r-x)+(r-y)*(r-y))-(r*r))< 350 && (((r-x)*(r-x)+(r-y)*(r-y))-(r*r))>=0){
                gout << move_to(pos_x+x,pos_y+y)<< color(255,255,255) <<dot;
            }
        }
    }

//mutatok
float x = cos(hour_deg)*50;
float y = sin(hour_deg)*50;

gout << move_to(pos_x+size_x/2,(pos_y+size_y/2))<< line_to(x+(pos_x+size_x/2),y+(pos_y+size_y/2)) << color(255,0,0) << box(5,5)     //ora
<<color(0,255,0) << move_to(pos_x+size_x/2,(pos_y+size_y/2))<< box(2,2);

 x = cos(min_deg)*100;
 y = sin(min_deg)*100;

 gout << move_to(pos_x+size_x/2,(pos_y+size_y/2))<< line_to(x+(pos_x+size_x/2),y+(pos_y+size_y/2)) << color(255,0,0) << box(5,5)     //ora
      <<color(0,255,0) << move_to(pos_x+size_x/2,(pos_y+size_y/2))<< box(2,2);

}

void ora:: set_time(double a, double b){
    hour=a;
    min=b;
}



void ora :: event(genv::event ev){
    if(ev.keycode == 'w'){
       cout << min;
    }
}









