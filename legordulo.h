#ifndef LEGORDULO_H
#define LEGORDULO_H
#include <vector>
#include <string>
#include "widget.h"
#include "graphics.hpp"

class legordulo : public widget{
protected:
    std::vector<std::string> v;
    int shift=0;
    int kivalasztott;
public:
    legordulo(int size_x, int size_y, int pos_x , int pos_y, std::vector<std::string> v, int shift, int kivalasztott);
    void rajzol() override;
    int get_shift();
    void set_shift(int a,int m_x, int m_y);
    void set_string(std::string a);
    std::string get_ertek(){return v[kivalasztott];};
    void kattintas(int m_x, int m_y);
    void event(genv::event ev) override;

};
#endif // LEGORDULO_H
