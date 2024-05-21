#include "widget.h"
#include <iostream>

widget::widget(int x, int y, int px , int py): size_x(x), size_y(y), pos_x(px), pos_y(py){}
bool widget :: active(int m_x, int m_y){
    if(m_x > pos_x && m_x < pos_x+size_x){
        if(m_y > pos_y && m_y < pos_y+size_y){
            return 1;
        }
    }
return 0;}
