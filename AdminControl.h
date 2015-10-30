#ifndef ADMINCONTROL_H
#define ADMINCONTROL_H

#include "MasterControl.h"
#include "adminview.h"
#include "ProfileEntity.h"
#include "project.h"
#include "projectframe.h"

#include <vector>

class MasterControl;

class AdminControl
{
public:
    AdminControl(MasterControl*, QWidget*);
	~AdminControl();
    void shutdown();


    void createProject(Project*);
    void saveProject();
    vector<Qualification*> getQualList();

    void logout(QPoint*);
    ProfileEntity* getLoggedUser();

    Project* getSelectedProject();
    void setSelectedProject(Project*);

    Project* getProject(int _index = -1, string _name = "");
    int getListSize();

    void setCurrentFrame(projectFrame*);
    projectFrame* getCurrentFrame();

private:
	MasterControl *m_Parent;
    QWidget *admin_window;
    vector<Project*> current_projects;

    Project* selected = 0;
    projectFrame* selected_Frame = 0;

    void gatherProjects();
};

#endif
