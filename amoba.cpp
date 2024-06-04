#include "graphics.hpp"
#include "amoba.h"
#include "widget.h"
#include <iostream>
#include <cmath>


using namespace genv;
using namespace std;

void kor(int pos_x ,int pos_y, int d){
    int r=d/2;
    for(int y=0; y<= d; y++){for(int x=0; x<= d; x++){
            if((((r-x)*(r-x)+(r-y)*(r-y))-(r*r))< 40 && (((r-x)*(r-x)+(r-y)*(r-y))-(r*r))>=0){
            gout << move_to(pos_x+x,pos_y+y)<< color(0,0,255) <<box(1,1);}
        }
    }
}
void X(int pos_x, int pos_y, int size_x, int size_y){
    gout << move_to(pos_x,pos_y) << color(255,0,0) << line_to(pos_x+size_x,pos_y+size_y);
    gout << move_to(pos_x,pos_y+size_y) << color(255,0,0) << line_to(pos_x+size_x,pos_y);

}

amoba::amoba(int size_x, int size_y, int pos_x , int pos_y, int seg): widget(size_x, size_y, pos_x, pos_y), seg(seg), v(seg, vector<int>(seg,0)) {}
void amoba::rajzol(){
    gout << move_to(pos_x,pos_y) << color(209,209,209) << box(size_x-10,size_y-10);// << move_to(pos_x+20,pos_y+20);
    //ha kek nyer:
    if(gameover==1){
        if(turn==-1){
            gout << move_to(pos_x+size_x/3,pos_y+size_y/4) << color(255,0,0) << text("PIROS nyert");
        }else{gout << move_to(pos_x+size_x/3,pos_y+size_y/4) << color(0,0,255) << text("KEK nyert");}
        gout << move_to(pos_x+180,pos_y+220) << color(90,90,90) << box(100,50) << color(0,0,0) << move_to(pos_x+190,pos_y+250) << text("restart");
    }
    if(gameover==2){
            gout << move_to(pos_x+size_x/2,pos_y+size_y/2) << color(0,255,0) << text("Betelt a palya");
        gout << move_to(pos_x+180,pos_y+220) << color(90,90,90) << box(100,50) << color(0,0,0) << move_to(pos_x+190,pos_y+250) << text("restart");
    }

    //ha jatek
    if(gameover==0){
    //rakjuk ki a negyzeteket
    for(int y=0; y<seg; y++){
        for(int x=0; x<seg; x++){
            if(v[x][y]==0){gout << move_to(2+pos_x+(size_x/seg)*x, 2+pos_y+(size_y/seg)*y) << color(180,180,180) << box(size_x/seg-4, size_y/seg-4);} //0 szurke
            if(v[x][y]==1){gout << move_to(2+pos_x+(size_x/seg)*x, 2+pos_y+(size_y/seg)*y) << color(180,180,180) << box(size_x/seg-4, size_y/seg-4); X(2+pos_x+(size_x/seg)*x, 2+pos_y+(size_y/seg)*y,size_x/seg-4, size_y/seg-4);} //1 piros
            if(v[x][y]==-1){gout << move_to(2+pos_x+(size_x/seg)*x, 2+pos_y+(size_y/seg)*y) << color(180,180,180) << box(size_x/seg-4, size_y/seg-4); kor(2+pos_x+(size_x/seg)*x, 2+pos_y+(size_y/seg)*y,size_x/seg-4);} //-1 kek
            }
        }
    }
}
bool amoba::ellenoriz(int vx, int vy, int turn) {
    int counter =0;
    for (int i=0-w+1;i<w;i++) // SOR check
        {
            if(vx+i >=0 && vx+i < seg){
            if (v[vx+i][vy] == turn)
                counter++;
            }
        }
    if (counter == w)
            return true;
    counter =0;
    for (int i=0-w+1;i<w;i++) // OSZLOP check
        {
            if(vy+i >=0 && vy+i < seg){
            if (v[vx][vy+i] == turn)
                counter++;
        }
    }

        if (counter == w)
            return true;
     counter =0;
    for (int i=0-w+1;i<w;i++) // FŐÁTLÓ check
        {
            if(vy+i >=0 && vy+i < seg && vx+i >=0 && vx+i < seg){
            if (v[vx+i][vy+i] == turn)
                counter++;
        }
     }
        if (counter == w)
            return true;
       counter =0;
        for (int i=0-w+1;i<w;i++) // MELLÉKÁTLÓ check
            {
                if(vy-i >=0 && vy-i < seg && vx+i >=0 && vx+i < seg){
                if (v[vx+i][vy-i] == turn)
                    counter++;
            }
          }
            return counter == w;
}
bool amoba::betelt(){
     for(int y=0; y<seg;y++){for(int x=0; x<seg; x++){
             if(v[x][y]==0){return 0; break;}
         }}
return 1;}

void amoba :: event(genv::event ev){

        int m_x =ev.pos_x;
        int m_y =ev.pos_y;
        if(gameover==1){
        if(m_x > pos_x && m_x < pos_x+size_x-10 && m_y > pos_y && m_y < pos_y+size_y-10 && ev.button ==-btn_left){
        if(m_x > pos_x+180 && m_y > pos_y+220 && m_x < pos_x+180+100 && m_y < pos_y+220+50){
            for(int y=0; y<seg;y++){for(int x=0; x<seg; x++){v[x][y]=0;}} //reset
            gameover=0;
            cout << "restart";
            }
            }
        }
        else if(gameover==2){
        if(m_x > pos_x && m_x < pos_x+size_x-10 && m_y > pos_y && m_y < pos_y+size_y-10 && ev.button ==-btn_left){
        if(m_x > pos_x+180 && m_y > pos_y+220 && m_x < pos_x+180+100 && m_y < pos_y+220+50){
            for(int y=0; y<seg;y++){for(int x=0; x<seg; x++){v[x][y]=0;}} //reset
            gameover=0;
            cout << "restart";
            }
            }
        }
        else if(gameover==0){
         if(m_x > pos_x && m_x < pos_x+size_x-10 && m_y > pos_y && m_y < pos_y+size_y-10 && ev.button ==-btn_left){
         int p_x = std::ceil((m_x-pos_x)/(size_x/seg));
         int p_y = std::ceil((m_y-pos_y)/(size_y/seg));
         if(v[p_x][p_y]==0){ //ha szurke a hatter
            v[p_x][p_y] = turn;
            if(ellenoriz(p_x,p_y,turn) ==1){
                if(turn ==1){
                   cout << "piros nyert" << " " << endl; gameover =1;
                    }else{
                    cout << "kek nyert" << " " << endl; gameover =1;
                    }
                }
            if(betelt()){gameover =2;}
                    turn*=-1;
                    }
                }
           }
    }
