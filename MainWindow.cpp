#include "MainWindow.h"
#include "widget.h"
using namespace genv;

MainWindow::MainWindow(int XX, int YY){
    gout.open(XX,YY);
}
void MainWindow::hozzaad(widget* w){
    widgets.push_back(w);
}
void MainWindow :: loop(){
    event ev;
    int index =-1;
       while(gin >> ev && ev.keycode != key_escape){
           if(ev.type==ev_mouse && ev.button == btn_left){
               for(size_t i=0; i<widgets.size(); i++){
                   if(widgets[i]->active(ev.pos_x, ev.pos_y)){
                       index =i;
                     //  cout << index;
                   }
               }
           }
           if(index!=-1){
               widgets[index]->event(ev);
           }
           for(widget* it: widgets){
               it->rajzol();
               gout << refresh;
           }
       }
}
