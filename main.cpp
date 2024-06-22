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
#include "screen.h"
#include "ora.h"
#include <map>
using namespace genv;
using namespace std;


int main(){
    MainWindow *window = new MainWindow(800, 600);

    ora* o = new ora(500, 50);
    window->hozzaad(o);

    szambeiro* s = new szambeiro(300,100);
    window->hozzaad(s);

    szambeiro* s2 = new szambeiro(300,170);
    window->hozzaad(s2);

    button* b = new button(300,50);
    b->megnyom=[&s,&s2, &o](){
        o->set_time(s->get_int(),s2->get_int());
    };
    b->set_string("set time");
    window->hozzaad(b);
/*                                                //partlistas
    vector<pair<string, int>>v;
    textedit* t1 =new textedit(50,10);
    window->hozzaad(t1);

    szambeiro* s1 =new szambeiro(50,60);
    window->hozzaad(s1);

    legordulo* l1 =new legordulo(300,50);
    window->hozzaad(l1);

    screen* sc =new screen(50,400);
    window->hozzaad(sc);

    button * b1 =new button(50,200);
    b1->megnyom=[&t1,&s1,&l1,&v,&sc](){
        v.push_back(make_pair(t1->get_string(),s1->get_int()));
        l1->push_string(t1->get_string()+'('+to_string(s1->get_int())+')');
        pair<string, int> leg=v[0];
        for(pair<string, int> &i : v){
            if(i.second>leg.second){leg=i;}
        }
        sc->set_string("A legnepszerubb part: "+ leg.first +'('+to_string(leg.second)+')');
    };
    b1->set_string("hozzaad");
    window->hozzaad(b1);

    button * b2 =new button(50,260);
    b2->megnyom=[&l1, &v, &sc](){
        v.erase(v.begin()+l1->get_kivalasztott_index());
        l1->erase_kivalasztott();
        pair<string, int> leg=v[0];
        for(pair<string, int> &i : v){
            if(i.second>leg.second){leg=i;}
        }
        sc->set_string("A legnepszerubb part: "+ leg.first +'('+to_string(leg.second)+')');
    };
    window->hozzaad(b2);

/*    legordulo* nevsor = new legordulo(10,10);   //donto
    window->hozzaad(nevsor);

    textedit* ujnev =new textedit(210,30);
    window->hozzaad(ujnev);

    button* ujadd =new button(210, 60);
    ujadd->set_string("Add versenyzo");
    ujadd->megnyom=[&ujnev, &nevsor, &window](){
        nevsor->push_string(ujnev->get_string());
        ujnev->set_string("");

        if(nevsor->list_size()==8){

            vector<pair<textedit*, button*>> semi; //masodik fordulo
            for(int i=0; i<4; i++){
                textedit* q1 = new textedit(280, 160+30*i);
                button* b1 = new button(490,160+30*i);
                b1->set_string("->");
                semi.push_back(make_pair(q1,b1));
                window->hozzaad(q1);
                window->hozzaad(b1);
            }

            vector<pair<textedit*, button*>> quart; //elso fordulo
            for(int i=0; i<8; i++){
                textedit* q1 = new textedit(20, 160+30*i);
                q1->set_string(nevsor->get_indexed(i));
                button* b1 = new button(230,160+30*i);
                b1->set_string("->");
                quart.push_back(make_pair(q1,b1));
                window->hozzaad(q1);
                window->hozzaad(b1);
            }
           for(int i=0 ;i<nevsor->list_size(); i++){
               quart[i].second->megnyom=[semi,i,quart](){
                    semi[0].first->set_string(quart[i].first->get_string());
                   cout << '(' << i <<')'<< endl;
                };
            }
        };

    };
    window->hozzaad(ujadd);
*/
    window->loop();
    delete window;

    return 0;
}
