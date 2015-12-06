#ifndef INTERFACEFACADE_H
#define INTERFACEFACADE_H

#include <QWidget>
#include "login.h"
#include "register.h"
#include "editqualifications.h"
#include "studentview.h"
#include "profileview.h"
#include "studentviewproject.h"


#include "LoginControl.h"
#include "AdminControl.h"
#include "StudentControl.h"

class MasterControl;
class AdminControl;
class StudentControl;

class InterfaceFacade
{
public:
    InterfaceFacade(MasterControl*);

    QWidget* GetForm(int, LoginControl*, int, int);
    QWidget* GetForm(int, LoginControl*, int, int, QString, int);

    QWidget* GetForm(int, StudentControl*, int, int);

    QWidget* GetForm(int, AdminControl*, int, int);


private:
    MasterControl *m_Parent;
    QWidget* CurrentUI;

};

#endif // INTERFACEFACADE_H
