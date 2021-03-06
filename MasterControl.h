#ifndef MASTERCONTROL_H
#define MASTERCONTROL_H

#include <QPoint>
#include <QWidget>
#include <QApplication>
#include "LoginControl.h"
#include "AdminControl.h"
#include "StudentControl.h"
#include "StorageManager.h"
#include "interfacefacade.h"

class LoginControl;
class AdminControl;
class StudentControl;
class InterfaceFacade;

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


    QWidget* GetForm(int, LoginControl*, int, int);
    QWidget* GetForm(int, LoginControl*, int, int, QString, int);

    QWidget* GetForm(int, StudentControl*, int, int);


    QWidget* GetForm(int, AdminControl*, int, int);
    QWidget* GetForm(int, AdminControl *, int, int, QString, QString, QString);

private:
    StorageManager* storage_control;
    LoginControl* login_control;
    AdminControl* admin_control;
    StudentControl* student_control;
    InterfaceFacade* InterfaceControl;


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
