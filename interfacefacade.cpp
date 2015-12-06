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

        std::cout << "Made the login" << std::endl;
    }
    if (id == 1)
    {
        QWidget* CurrentUI = new Register(pointer, NULL, x, y);

    }

    return CurrentUI;
}


QWidget* InterfaceFacade::GetForm(int id, StudentControl* pointer, int x, int y){
}



QWidget* InterfaceFacade::GetForm(int, AdminControl*, int, int){

}



