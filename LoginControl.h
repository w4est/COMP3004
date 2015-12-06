#ifndef LOGINCONTROL_H
#define LOGINCONTROL_H

#include "MasterControl.h"
#include "ProfileEntity.h"
#include "login.h"
#include "qualification.h"


class MasterControl;

class LoginControl
{
public:
    LoginControl(MasterControl*, QWidget*);
	~LoginControl();
    void shutdown();
    MasterControl* getMParent();

    int userExists(string);
    void loginUser(string, QPoint*);
    void registerUser();
    bool registerTempUser(string);
    void unregisterTempUser(string);
    ProfileEntity* getCurrentUser();
    const vector<Qualification*>& getQualList();

private:
	MasterControl *m_Parent;
	ProfileEntity *user;
    QWidget *login_window;
};

#endif
