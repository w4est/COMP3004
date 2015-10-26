#include "MasterControl.h"

MasterControl::MasterControl()
    :storage_control(0), login_control(0)
{
    storage_control = new StorageManager();
    if(storage_control){
        cout << "storage made" << endl;
    }
    else{
        cout << "storage not made" << endl;
    }
    login_control = new LoginControl(this);

}


MasterControl::~MasterControl()
{
    if (storage_control == 0) delete storage_control;
    if (login_control == 0) delete login_control;
}

StorageManager& MasterControl::getStorageAccess()
{
	return *storage_control;
}

void MasterControl::setUserProfile(ProfileEntity& _user)
{
	current_user_profile = &_user;
}

void MasterControl::completeLogin()
{
	if (current_user_profile){
		delete login_control;
	}
}
