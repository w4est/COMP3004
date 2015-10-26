#ifndef MASTER_CONTROL_H
#define MASTER_CONTROL_H

#include "LoginControl.h"
#include "StorageManager.h"
class LoginControl;

class MasterControl
{
public:
	MasterControl();
	~MasterControl();

	StorageManager& getStorageAccess();
	void setUserProfile(ProfileEntity&);
	void completeLogin();

private:
    StorageManager* storage_control;
    LoginControl* login_control;
	ProfileEntity* current_user_profile;

};

#endif
