//#include "login.h"
#include "MasterControl.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *Window;
    Window = NULL;

    //Window->show();
    //Window.show();
    MasterControl* control = new MasterControl(Window);


    //TODO UNDO THIS
    return a.exec();
    //return 0;

    delete (Window);
    delete (control);
}
