#include "AdminControl.h"

AdminControl::AdminControl(MasterControl* _control, QWidget* _parent)
{
    m_Parent = _control;
    this->gatherProjects();

    admin_window = new AdminView(this, _parent);
    admin_window->show();
}


AdminControl::~AdminControl()
{
    m_Parent = 0;

    //if(admin_window) delete admin_window;
}

void AdminControl::createProject(Project* _project)
{
    m_Parent->getStorageAccess().createProject(*_project);
    current_projects.push_back(_project);
}

void AdminControl::logout(QPoint *_point)
{
    m_Parent->logout(_point);
}

ProfileEntity* AdminControl::getLoggedUser()
{
    return m_Parent->getLoggedUser();
}

//

void AdminControl::gatherProjects()
{
    current_projects = m_Parent->getStorageAccess().getProjectList();
}

Project* AdminControl::getProject(int _index, string _name)
{
    if(_index < 0 || _index > current_projects.size()){
        for(int i = 0; i < current_projects.size(); i++)
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

int AdminControl::getListSize()
{
    return current_projects.size();
}
