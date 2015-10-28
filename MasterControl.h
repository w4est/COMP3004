#ifndef MASTERCONTROL_H
#define MASTERCONTROL_H

#include <QPoint>
#include <QWidget>
#include "LoginControl.h"
#include "AdminControl.h"
#include "StudentControl.h"
#include "StorageManager.h"

class LoginControl;
class AdminControl;
class StudentControl;

class MasterControl
{
public:
    MasterControl(QWidget*);
	~MasterControl();

	StorageManager& getStorageAccess();

	void setUserProfile(ProfileEntity&);
    void completeLogin(QPoint* _point = 0);
    void logout(QPoint* _point = 0);
    const QPoint* getLastPoint();

private:
    StorageManager* storage_control;
    LoginControl* login_control;
    AdminControl* admin_control;
    StudentControl* student_control;


	ProfileEntity* current_user_profile;
    QPoint* lastPoint;
    QWidget *parent, *twin;

    void changePoint(QPoint*);
    void createLoginControl();
    void createAdminControl();
    void createStudentControl();

};

#endif
