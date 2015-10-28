//#include "login.h"
#include "MasterControl.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Login w;
    QWidget *Window;
    Window = NULL;
    //Window = new Login(Window);
    //Window->show();
    //w.show();
    MasterControl* control = new MasterControl(Window);


    //TODO UNDO THIS
    return a.exec();
    //return 0;
    delete (Window);
    delete (control);
}
