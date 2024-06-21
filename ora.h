#ifndef ORA_H
#define ORA_H
#include "widget.h"
#include <cmath>

class ora : public widget{
protected:
    int hour;
    int min;
    float hour_deg;
    float min_deg;
    double pi = 2 * acos(0.0);
public:
    ora(int pos_x, int pos_y);
    void rajzol();
    void event(genv::event ev);
    void set_time(double h, double m);
};

#endif // ORA_H
