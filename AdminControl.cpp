#include "AdminControl.h"

AdminControl::AdminControl(MasterControl* _control, QWidget* _parent)
{
    m_Parent = _control;


    admin_window = new AdminView(this, _parent);
    admin_window->show();
    std::cout << "ADMINCONTROL:: ctor" << std::endl;
}


AdminControl::~AdminControl()
{
    m_Parent = 0;

    if(admin_window) delete admin_window;
    std::cout << "ADMINCONTROL:: dtor" << std::endl;
}

void AdminControl::logout(QPoint *_point)
{
    m_Parent->logout(_point);
}
