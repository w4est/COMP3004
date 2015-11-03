//#include "login.h"
#include "MasterControl.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *Window;
    Window = NULL; //Was used for debugging.

    //Window->show();
    //Window.show();
    MasterControl* control = new MasterControl(&a, Window);



    return a.exec();


    delete (Window);
    delete (control);
    return 0;
}
