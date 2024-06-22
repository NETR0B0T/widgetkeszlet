#include "graphics.hpp"
#include "ora.h"
#include "widget.h"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
using namespace genv;
using namespace std;


ora::ora(int pos_x, int pos_y):widget(200,200, pos_x, pos_y), hour(0), min(0), hour_deg(0), min_deg(0), sec(0), sec_deg(0){};

void ora :: rajzol(){

    sec_deg=(sec/60)*2*pi-pi/2;

    min_deg=(min/60)*2*pi-pi/2;


    if (hour<=12){
    hour_deg=hour*(2*pi)/12-(pi/2)+min/60*pi/6;}
    else{hour_deg=(hour-12)*(2*pi)/12-pi/2+min/60*pi/6;}

    gout << move_to(pos_x, pos_y);
        int r= size_x/2;
    for(int y=0; y<= size_y; y++){for(int x=0; x<= size_x; x++){
            if((((r-x)*(r-x)+(r-y)*(r-y))<=r*r)){
            gout << move_to(pos_x+x,pos_y+y) << color(100,100,100) << dot;}else if((((r-x)*(r-x)+(r-y)*(r-y))-(r*r))< 350 && (((r-x)*(r-x)+(r-y)*(r-y))-(r*r))>=0){
                gout << move_to(pos_x+x,pos_y+y)<< color(255,255,255) <<dot;
            }
        }
    }

    float linedeg=-pi/2;    //beosztas
    float x;
    float y;

    for(int i =0; i<60; i++){
        x = cos(linedeg)*100;
        y = sin(linedeg)*100;
        gout << move_to(pos_x+size_x/2,(pos_y+size_y/2))<< line_to(x+(pos_x+size_x/2),y+(pos_y+size_y/2)) << color(255,255,255);
        linedeg-=pi/30;
    }

    gout << move_to(pos_x, pos_y); //beosztas takaro
    r= size_x/2-5;
    for(int y=0; y<= size_y; y++){for(int x=0; x<= size_x; x++){
            if((((r-x)*(r-x)+(r-y)*(r-y))<=r*r)){
                gout << move_to(pos_x+x+5,pos_y+y+5) << color(100,100,100) << dot;}
        }
    }

    //secondary beosztas

    linedeg=-pi/2;

    for(int i =0; i<=12; i++){
        x = cos(linedeg)*100;
        y = sin(linedeg)*100;
        gout << move_to(pos_x+size_x/2,(pos_y+size_y/2))<< line_to(x+(pos_x+size_x/2),y+(pos_y+size_y/2)) << color(255,255,255);
        linedeg-=pi/6;
    }

    //secondary beosztas takaro

    r= size_x/2-10;
    for(int y=0; y<= size_y; y++){for(int x=0; x<= size_x; x++){
            if((((r-x)*(r-x)+(r-y)*(r-y))<=r*r)){
                gout << move_to(pos_x+x+10,pos_y+y+10) << color(100,100,100) << dot;}
        }
    }

    float szamdeg=-pi/2;    //szamlap

    for(int i =0; i<12; i++){
        x = cos(szamdeg)*82;
        y = sin(szamdeg)*82;
        gout << move_to(x+(pos_x+size_x/2)-6,y+(pos_y+size_y/2)-10) << color(255,255,255) <<text(to_string(12-i));
        szamdeg-=pi/6;
    }


//mutatok
 x = cos(hour_deg)*50;
 y = sin(hour_deg)*50;

gout << move_to(pos_x+size_x/2,(pos_y+size_y/2))<< line_to(x+(pos_x+size_x/2),y+(pos_y+size_y/2)) << box(2,2);     //ora;

 x = cos(min_deg)*95;
 y = sin(min_deg)*95;

 gout << move_to(pos_x+size_x/2,(pos_y+size_y/2))<< line_to(x+(pos_x+size_x/2),y+(pos_y+size_y/2)) << box(2,2);     //perc;

 x = cos(sec_deg)*100;
 y = sin(sec_deg)*100;

 gout <<color(255,0,0)<< move_to(pos_x+size_x/2,(pos_y+size_y/2))<< line_to(x+(pos_x+size_x/2),y+(pos_y+size_y/2)) << box(2,2);    //masodperc
}



void ora:: set_time(double a, double b){
    hour=a;
    min=b;
}



void ora :: event(genv::event ev){
    if(ev.type==ev_timer){
        sec++;
    }
    if(sec==60){
        min++;
        sec=0;
    }
    if(min==60){
        hour++;
        min=0;
    }
    if(hour==24){
        hour=0;
    }
}









