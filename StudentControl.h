#ifndef STUDENTCONTROL_H
#define STUDENTCONTROL_H

#include "MasterControl.h"
#include "profileview.h"

class MasterControl;

class StudentControl
{
public:
    StudentControl(MasterControl*, QWidget*);
	~StudentControl();

    void logout(QPoint*);
    void shutdown();

private:
	MasterControl* m_Parent;
    QWidget *student_window;
};

#endif
