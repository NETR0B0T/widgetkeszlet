#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>
#include <sstream>
#include <fstream>
#include "widget.h"
#include "szambeiro.h"
#include "legordulo.h"
#include "MainWindow.h"
#include "textedit.h"
#include "checkbox.h"
#include "button.h"
using namespace genv;
using namespace std;


int main(){
    MainWindow *window = new MainWindow(600, 600);

    legordulo* l = new legordulo(10, 10);
    window->hozzaad(l);

    legordulo* l2 = new legordulo(350, 10);
    window->hozzaad(l2);

    textedit* t = new textedit(10, 450);
    window->hozzaad(t);

    button* b = new button(400, 450);
    b->set_string("szovegbol");
    window->hozzaad(b);
    b->megnyom = [&l, &t](){l->push_string(t->get_string());};

    szambeiro * s = new szambeiro(10, 510);
    window->hozzaad(s);

    button* b2 = new button(400, 510);
    window->hozzaad(b2);
    b2->set_string("szambol");
    b2->megnyom =[&s, &l](){l->push_string(to_string(s->get_int()));};

    button* b3 = new button(250, 100);
    window->hozzaad(b3);
    b3->set_string("erase");
    b3->megnyom =[&l](){   //törlő gomb
        l->erase_kivalasztott();
    };

    button* b4 = new button(250, 300);
    window->hozzaad(b4);
    b4->set_string("->");
    b4->megnyom =[&l, &l2](){   //atvivo
        if(l->ures()==0){
        l2->push_string(l->get_kivalasztott());}
        l->erase_kivalasztott();
    };

    window->loop();
    delete window;

    return 0;
}
