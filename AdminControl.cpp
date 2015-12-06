#include "AdminControl.h"

AdminControl::AdminControl(MasterControl* _control, QWidget* _parent)
{
    m_Parent = _control;
    this->gatherProjects();

    admin_window = m_Parent->GetForm(7,this,m_Parent->getLastPoint()->x(), m_Parent->getLastPoint()->y());
            //new AdminView(this, _parent, m_Parent->getLastPoint()->x(), m_Parent->getLastPoint()->y());
    //admin_window->show();
}


AdminControl::~AdminControl()
{
    m_Parent = 0;

    //if(admin_window) admin_window->deleteLater();
    admin_window = NULL;
}

void AdminControl::shutdown()
{
    m_Parent->kill();
}

void AdminControl::createProject(Project* _project)
{
    m_Parent->getStorageAccess().createProject(*_project);
    current_projects.push_back(_project);
    saveProject();
}

void AdminControl::saveProject()
{
    m_Parent->getStorageAccess().saveProjects();
}

vector<Qualification*> AdminControl::getQualList()
{
    return m_Parent->getStorageAccess().getQualificationList();
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

int AdminControl::getListSize()
{
    return current_projects.size();
}

Project* AdminControl::getSelectedProject()
{
    return selected;
}

void AdminControl::setSelectedProject(Project *_project)
{
    selected = _project;
}

void AdminControl::setCurrentFrame(projectFrame *_frame)
{
    if(selected_Frame){
        selected_Frame->setStyleSheet("");
    }
    selected_Frame = _frame;
}

projectFrame* AdminControl::getCurrentFrame()
{
    return selected_Frame;
}

MasterControl* AdminControl::getMParent()
{
    return m_Parent;
}
