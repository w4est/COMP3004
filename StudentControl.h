#ifndef STUDENTCONTROL_H
#define STUDENTCONTROL_H

#include "MasterControl.h"
#include "profileview.h"
#include "studentview.h"
#include "ProfileEntity.h"
#include "StorageManager.h"
#include "stuprojectframe.h"
#include "studentviewproject.h"


#include <vector>

class MasterControl;
class stuProjectFrame;

class StudentControl
{
public:
    StudentControl(MasterControl*, QWidget*);
	~StudentControl();

    void logout(QPoint*);
    void ViewProfile(QWidget*,int,int);
    void StudentPage(QWidget*,int,int);
    void ViewProject(QWidget*,int,int);
    void shutdown();
    const vector<Qualification*>& getQualList();
    ProfileEntity* getLoggedUser();
    StorageManager& getStorageAccess();
    Project* getSelectedProject();
    int getListSize();
    Project* getProject(int _index = -1, string _name = "");
    void setSelectedProject(Project*);
    void setCurrentFrame(stuProjectFrame*);
    stuProjectFrame* getCurrentFrame();

    MasterControl* getMParent();


private:
	MasterControl* m_Parent;
    QWidget *student_window;
    void gatherProjects();

    Project* selected = 0;
    stuProjectFrame* selected_Frame = 0;
    vector<Project*> current_projects;

};

#endif
