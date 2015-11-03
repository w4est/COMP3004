#ifndef STUDENTCONTROL_H
#define STUDENTCONTROL_H

#include "MasterControl.h"
#include "profileview.h"
#include "studentview.h"
#include "ProfileEntity.h"
#include "StorageManager.h"

class MasterControl;

class StudentControl
{
public:
    StudentControl(MasterControl*, QWidget*);
	~StudentControl();

    void logout(QPoint*);
    void ViewProfile(QWidget*,int,int);
    void StudentPage(QWidget*,int,int);
    void shutdown();
    const vector<Qualification*>& getQualList();
    ProfileEntity* getLoggedUser();
    StorageManager& getStorageAccess();

private:
	MasterControl* m_Parent;
    QWidget *student_window;
};

#endif
