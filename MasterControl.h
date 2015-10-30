#ifndef MASTERCONTROL_H
#define MASTERCONTROL_H

#include <QPoint>
#include <QWidget>
#include <QApplication>
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
    MasterControl(QApplication* _app, QWidget* _parent = 0);
	~MasterControl();

	StorageManager& getStorageAccess();

	void setUserProfile(ProfileEntity&);
    void completeLogin(QPoint* _point = 0);
    void logout(QPoint* _point = 0);
    void kill();
    const QPoint* getLastPoint();

    ProfileEntity* getLoggedUser();

private:
    StorageManager* storage_control;
    LoginControl* login_control;
    AdminControl* admin_control;
    StudentControl* student_control;


	ProfileEntity* current_user_profile;
    QPoint* lastPoint;
    QWidget *parent;
    QApplication* app;

    void changePoint(QPoint*);
    void createLoginControl();
    void createAdminControl();
    void createStudentControl();


};

#endif
