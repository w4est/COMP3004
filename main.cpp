#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //Create Application
    QApplication a(argc, argv);
    //Create the window container as a passable pointer
    QWidget *Window;
    Window = NULL;

    //Pass the window container to the login page and show it
    Window = new Login(Window);
    Window->show();




    return a.exec(); //Execute
}
