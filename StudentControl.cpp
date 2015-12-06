#include "StudentControl.h"


StudentControl::StudentControl(MasterControl* _control, QWidget* _parent)
{
    m_Parent = _control;
    this->gatherProjects();

    student_window = m_Parent->GetForm(3,this,m_Parent->getLastPoint()->x(), m_Parent->getLastPoint()->y());
            //new StudentView(this, _parent, m_Parent->getLastPoint()->x(), m_Parent->getLastPoint()->y());
    //student_window->show();
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

    student_window = m_Parent->GetForm(4,this,x,y);
            //new ProfileView(this, _parent, x, y);
    //student_window->show();
}

/*
 * Create another StudentView,
 *
 *
 * */
void StudentControl::StudentPage(QWidget *_parent, int x, int y)
{

    student_window = m_Parent->GetForm(3,this,x,y);
            //new StudentView(this, _parent, x, y);
    //student_window->show();
}


/*
 * Create StudentViewProject,
 *
 *
 * */
void StudentControl::ViewProject(QWidget *_parent, int x, int y)
{

    student_window = m_Parent->GetForm(5,this,x,y);
            //new studentViewProject(this, _parent, x, y);
    //student_window->show();
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


/*
 * Get storage access
 *
 *
 * */
StorageManager& StudentControl::getStorageAccess(){

    return m_Parent->getStorageAccess();
}

/*
 * Return Projects
 *
 * */

void StudentControl::gatherProjects()
{
    current_projects = m_Parent->getStorageAccess().getProjectList();
}


/*
 * Get a project's details
 *
 * */
Project* StudentControl::getProject(int _index, string _name)
{
    this->gatherProjects();
    if(_index < 0 || (unsigned int)_index > current_projects.size()){
        for(unsigned int i = 0; i < current_projects.size(); i++)
        {
            if(_name.compare(current_projects.at(i)->getProjectName()) == 0)
            {
                return current_projects.at(i);
            }
        }
        return 0;
    }
    return current_projects.at(_index);
}

/*
 * Get how many projects are available
 *
 * */
int StudentControl::getListSize()
{
    return current_projects.size();
}


/*
 * Get Selected Project.
 *
 * */
Project* StudentControl::getSelectedProject()
{
    return selected;
}


/*
 * Frame controlling functions
 *
 * */

void StudentControl::setSelectedProject(Project *_project)
{
    selected = _project;
}

void StudentControl::setCurrentFrame(stuProjectFrame *_frame)
{
    if(selected_Frame){
        selected_Frame->setStyleSheet("");
    }
    selected_Frame = _frame;
}

stuProjectFrame* StudentControl::getCurrentFrame()
{
    return selected_Frame;
}

