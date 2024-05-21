#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <vector>

class widget;

class MainWindow{
        protected:
        std::vector<widget*> widgets;
    public:
        MainWindow(int XX, int YY);
        ~MainWindow()=default;
        void hozzaad(widget*);
        void loop();
    };
#endif // MAINWINDOW_H
