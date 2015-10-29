#ifndef ADMINCONTROL_H
#define ADMINCONTROL_H

#include "MasterControl.h"
#include "adminview.h"
#include "ProfileEntity.h"
#include "project.h"

#include <vector>

class MasterControl;

class AdminControl
{
public:
    AdminControl(MasterControl*, QWidget*);
	~AdminControl();

    void createProject(Project*);

    void logout(QPoint*);
    ProfileEntity* getLoggedUser();

    Project* getProject(int _index = -1, string _name = "");
    int getListSize();

private:
	MasterControl *m_Parent;
    QWidget *admin_window;
    vector<Project*> current_projects;

    void gatherProjects();
};

#endif
