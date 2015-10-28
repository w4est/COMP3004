#ifndef ADMINCONTROL_H
#define ADMINCONTROL_H

#include "MasterControl.h"
#include "adminview.h"

class MasterControl;

class AdminControl
{
public:
    AdminControl(MasterControl*, QWidget*);
	~AdminControl();

    void logout(QPoint*);

private:
	MasterControl *m_Parent;
    QWidget *admin_window;
};

#endif
