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
    legordulo(int pos_x , int pos_y);
    void rajzol() override;
    std::string get_indexed(int i);
    void set_shift(int a,int m_x, int m_y);
    void push_string(std::string a);
    void push_int(int a);
    void kattintas(int m_x, int m_y);
    void event(genv::event ev) override;
    void erase_kivalasztott();
    int list_size();
    std::string get_kivalasztott();

};
#endif // LEGORDULO_H
