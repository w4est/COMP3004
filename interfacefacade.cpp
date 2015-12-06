#include "interfacefacade.h"

InterfaceFacade::InterfaceFacade(MasterControl* _control)
{
}


/*
 * Create an UI for the cuPID system to use,
 * Cupid should be responsible for deleting the UI called.
 *
 * id belongs to the following forms:
 * 00 = Login
 * 01 = Register
 * 02 = EditQualifications
 * 03 = StudentView
 * 04 = StudentViewProfile
 * 05 = ProfileView
 * 06 = StudentViewProject
 * 07 = AdminView
 * 08 = AdminCreateProject
 * 09 = AdminCreateProject2
 * 10 = EditProject
 * 11 = RunPPid
 * 12 = ResultsPage
 * 13 = qualFrame
 * 14 = ProjectFrame
 * 15 = StuProjectFrame
 *
 * */



QWidget* InterfaceFacade::GetForm(int id, LoginControl* pointer, int x, int y){

    if (id == 0)
    {
        QWidget* CurrentUI = new Login(pointer, NULL, x,y);
        CurrentUI->show();


    }
    if (id == 1)
    {
        QWidget* CurrentUI = new Register(pointer, NULL, x, y);
        CurrentUI->show();
    }



    return CurrentUI;
}

QWidget* InterfaceFacade::GetForm(int id, LoginControl* pointer, int x, int y, QString username, int page){
    if (id == 1)
    {
        QWidget* CurrentUI = new Register(pointer, NULL, x, y,username);
        CurrentUI->show();

    }
    if (id == 2)
    {
        QWidget* CurrentUI = new EditQualifications(pointer, NULL, x, y,username, page);
        CurrentUI->show();

    }
    return CurrentUI;
}
QWidget* InterfaceFacade::GetForm(int id, StudentControl* pointer, int x, int y){

    if (id == 3){
        QWidget* CurrentUI = new StudentView(pointer, NULL, x, y);
        CurrentUI->show();
    }
    else if (id == 4){
        QWidget* CurrentUI = new ProfileView(pointer, NULL, x, y);
        CurrentUI->show();

    }
    else if (id == 5){
        QWidget* CurrentUI = new studentViewProject(pointer, NULL, x, y);
        CurrentUI->show();

    }
    else if (id == 6){


    }
    return CurrentUI;
}



QWidget* InterfaceFacade::GetForm(int, AdminControl*, int, int){

}



