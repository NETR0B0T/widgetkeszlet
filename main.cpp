#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>
#include <sstream>
#include <fstream>
#include "widget.h"
#include "amoba.h"
#include "szambeiro.h"
#include "MainWindow.h"
using namespace genv;
using namespace std;


int main(){
    MainWindow *window = new MainWindow(1300, 600);
    szambeiro* s =new szambeiro(100,50, 10,50, 0);
    window->hozzaad(s);
    window->loop();
    delete window;

    return 0;
}
