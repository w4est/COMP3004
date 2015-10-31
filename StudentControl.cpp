#include "StudentControl.h"


StudentControl::StudentControl(MasterControl* _control, QWidget* _parent)
{
    m_Parent = _control;

    student_window = new ProfileView(this, _parent);
    student_window->show();
}

StudentControl::~StudentControl()
{
    m_Parent = 0;

    //if(student_window) delete student_window;
    student_window = NULL;
}

void StudentControl::shutdown()
{
    m_Parent->kill();
}

void StudentControl::logout(QPoint *_point)
{
    m_Parent->logout(_point);
}
