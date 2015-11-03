#include "StudentControl.h"


StudentControl::StudentControl(MasterControl* _control, QWidget* _parent)
{
    m_Parent = _control;

    student_window = new StudentView(this, _parent, m_Parent->getLastPoint()->x(), m_Parent->getLastPoint()->y());
    student_window->show();
}

StudentControl::~StudentControl()
{
    m_Parent = 0;

    //if(student_window) delete student_window
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

/*
 * Create a ViewProfile
 *
 *
 * */
void StudentControl::ViewProfile(QWidget *_parent, int x, int y)
{

    student_window = new ProfileView(this, _parent, x, y);
    student_window->show();
}

/*
 * Create another StudentView,
 *
 *
 * */
void StudentControl::StudentPage(QWidget *_parent, int x, int y)
{

    student_window = new StudentView(this, _parent, x, y);
    student_window->show();
}

/*
 * Get the qualification list from the master control
 * */

const vector<Qualification*>& StudentControl::getQualList()
{
    return m_Parent->getStorageAccess().getQualificationList();
}

/*
 * Get Profile Entity for account
 * */

ProfileEntity* StudentControl::getLoggedUser()
{
    return m_Parent->getLoggedUser();
}

StorageManager& StudentControl::getStorageAccess(){

    return m_Parent->getStorageAccess();
}
