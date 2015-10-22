#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Login w;
    QWidget *Window;
    Window = new Login;
    Window->show();
    //w.show();

    return a.exec();
}
