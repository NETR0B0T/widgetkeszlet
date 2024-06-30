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
    float num;
    bool add=0;
    bool sub=0;
    bool mult=0;
    bool div=0;
    screen* s = new screen(50,50);              //screen
    window->hozzaad(s);

    button* x = new button(430,50);            //delete
    x->set_string("<-");
    x->megnyom=[&s](){
        if(s->get_string()!="bro."){
        string str = s->get_string();
        if(str.length()>0){
            str.erase(str.end()-1);
        s->set_string(str);
        }
        }
    };

    button* clear = new button(480,50);
    clear->megnyom=[&s](){
        s->set_string("");
    };
    clear->set_string("x");
    window->hozzaad(clear);

    window->hozzaad(x);                         //gombok
    int lerak_x=50;
    int lerak_y=100;
    int db=0;
    for(int i=0; i<=9; i++){
        button *b= new button(lerak_x+db*50, lerak_y);
        if((i+1)%3==0){
            lerak_y+=50;}
        if(db==2){
            db=0;
        }else{db++;}
        b->set_string(to_string(i));
        b->megnyom=[&s, i](){
                if(s->get_string()=="bro."){
                    s->set_string("");
                }
                s->add_string(to_string(i));
        };
        window->hozzaad(b);
    }

    button* osszead =new button(250,100);       //osszeadas
    osszead->set_string(" + ");
    osszead->megnyom= [&s, &num, &add](){
        if(s->get_string()!="" && s->get_string()!="bro."){
        num=stof(s->get_string());
        s->set_string("");
        add=1;
        }
    };
    window->hozzaad(osszead);

    button* kivon =new button(250,150);         //kivonas
    kivon->set_string(" - ");
    kivon->megnyom= [&s, &num, &sub](){
        if(s->get_string()!="" && s->get_string()!="bro."){
        num=stof(s->get_string());
        s->set_string("");
        sub=1;
        }
    };
    window->hozzaad(kivon);

    button* szoroz =new button(250,200);         //szorzas
    szoroz->set_string(" * ");
    szoroz->megnyom= [&s, &num, &mult](){
        if(s->get_string()!="" && s->get_string()!="bro."){
        num=stof(s->get_string());
        s->set_string("");
        mult=1;
        }
    };
    window->hozzaad(szoroz);

    button* oszt =new button(250,250);         //osztas
    oszt->set_string(" / ");
    oszt->megnyom= [&s, &num, &div](){
        if(s->get_string()!="" && s->get_string()!="bro."){
        num=stof(s->get_string());
        s->set_string("");
        div=1;
        }
    };
    window->hozzaad(oszt);

    button* egyenlo =new button(300,100);      //egyenlo
    egyenlo->set_string("=");
    egyenlo->megnyom=[&div, &mult, &sub, &add, &num, &s](){
        if(s->get_string()!=""){
        if(add==1){
          if(stof(s->get_string())+num==stoi(s->get_string())+int(num)){
            s->set_string(to_string(stoi(s->get_string())+int(num)));
          }else{
            s->set_string(to_string(stof(s->get_string())+num));
          }
       add=0;
        }

        if(sub==1){
            if(num-stof(s->get_string())==int(num)-stoi(s->get_string())){
              s->set_string(to_string(int(num)-stoi(s->get_string())));
            }else{
              s->set_string(to_string(num-stof(s->get_string())));
            }
        sub=0;
        }

        if(mult==1){
            if(num*stof(s->get_string())==int(num)*stoi(s->get_string())){
              s->set_string(to_string(int(num)*stoi(s->get_string())));
            }else{
              s->set_string(to_string(num*stof(s->get_string())));
            }
        mult=0;
        }

        if(div==1){
            if (s->get_string()=="0"){
                 s->set_string("bro.");
                }else{
                if(num/stof(s->get_string())==int(num)/stoi(s->get_string())){
                  s->set_string(to_string(int(num)/stoi(s->get_string())));
                }else{
                  s->set_string(to_string(num/stof(s->get_string())));
                }
               }
        div=0;
        }
        }
    };
    window->hozzaad(egyenlo);

/*
    ora* o = new ora(500, 50);              // ora
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
 */
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
