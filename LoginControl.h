#ifndef LOGIN_CONTROL_H
#define LOGIN_CONTROL_H

#include "MasterControl.h"
#include "ProfileEntity.h"
#include "login.h"


class MasterControl;

class LoginControl
{
public:
	LoginControl(MasterControl*);
	~LoginControl();

	bool userExists(string);
	void loginUser(string);
    bool registerTempUser(string);
    void unregisterTempUser(string);

private:
	MasterControl *m_Parent;
	ProfileEntity *user;
    QWidget *login_window;
};

#endif
