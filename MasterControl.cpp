#include "MasterControl.h"

MasterControl::MasterControl(QWidget* _parent)
{
    current_user_profile = 0;
    login_control = 0;
    admin_control = 0;
    student_control = 0;
    lastPoint = 0;

    storage_control = new StorageManager();
    parent = _parent;

    createLoginControl();
}


MasterControl::~MasterControl()
{
    if (current_user_profile) delete current_user_profile;
    if (login_control) delete login_control;
    if (admin_control) delete admin_control;
    if (student_control) delete student_control;
    if (storage_control) delete storage_control;
    if (lastPoint) delete lastPoint;
}

StorageManager& MasterControl::getStorageAccess()
{
	return *storage_control;
}

void MasterControl::createLoginControl()
{
    if(!login_control){
        login_control = new LoginControl(this, parent);
    }
}

void MasterControl::createAdminControl()
{

    if(!admin_control){
        cout << "MASTERCONTROL:: createAdmin" << endl;
        admin_control = new AdminControl(this, parent);
    }
}

void MasterControl::createStudentControl()
{
    if(!student_control){
        student_control = new StudentControl(this, parent);
    }
}

void MasterControl::setUserProfile(ProfileEntity& _user)
{
	current_user_profile = &_user;
}

void MasterControl::completeLogin(QPoint* _point)
{
    if (current_user_profile)
    {
        changePoint(_point);

        delete login_control;
        login_control = 0;

        if(current_user_profile->isAdmin()){
            createAdminControl();
        }
        else{
            createStudentControl();
        }
	}
}

void MasterControl::logout(QPoint* _point)
{
    if(current_user_profile)
    {
        changePoint(_point);

        bool admin = current_user_profile->isAdmin();
        delete current_user_profile;
        current_user_profile = 0;

        if(admin){
            delete admin_control;
            admin_control = 0;
        }
        else{
            delete student_control;
            student_control = 0;
        }
        createLoginControl();
    }
}

const QPoint* MasterControl::getLastPoint()
{
    return lastPoint;
}

void MasterControl::changePoint(QPoint *_point)
{
    if(lastPoint){
        delete lastPoint;
    }
    lastPoint = _point;
}
