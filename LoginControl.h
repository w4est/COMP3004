#ifndef LOGINCONTROL_H
#define LOGINCONTROL_H

#include "MasterControl.h"
#include "ProfileEntity.h"
#include "login.h"


class MasterControl;

class LoginControl
{
public:
    LoginControl(MasterControl*, QWidget*);
	~LoginControl();

    int userExists(string);
    void loginUser(string, QPoint*);
    void registerUser();
    bool registerTempUser(string);
    void unregisterTempUser(string);
    ProfileEntity* getCurrentUser();
    void getQualList(vector<pair<string, tuple<int, int, int, int>>>&);

private:
	MasterControl *m_Parent;
	ProfileEntity *user;
    QWidget *login_window;
};

#endif
