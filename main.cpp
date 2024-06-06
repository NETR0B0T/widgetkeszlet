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
#include <map>
using namespace genv;
using namespace std;


int main(){
    MainWindow *window = new MainWindow(800, 600);

    legordulo* nevsor = new legordulo(10,10);
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
                button* b1 = new button(230,160+30*i);
                b1->set_string("->");
                b1->megnyom=[&q1,&semi,&i](){
                   // semi[i].first->set_string(q1->get_string());
                    cout<<endl<<i<<endl;
                };
                quart.push_back(make_pair(q1,b1));
                window->hozzaad(q1);
                window->hozzaad(b1);

            }
            for(int i=0 ;i<nevsor->list_size(); i++){
                quart[i].first->set_string(nevsor->get_indexed(i));
            }
        };

    };
    window->hozzaad(ujadd);

    window->loop();
    delete window;

    return 0;
}
