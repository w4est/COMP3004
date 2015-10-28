#ifndef ADMIN_CONTROL_H
#define ADMIN_CONTROL_H

#include <QDialog>
#include "login.h"
#include "project.h"
#include "createproject.h"
#include "runppid.h"
#include "editproject.h"

namespace Ui {
class adminControl;
}

class adminControl : public QDialog
{
    Q_OBJECT

public:
    explicit adminControl(QWidget *parent = 0, int _x = 150, int _y = 50, QString _username = "");
    ~adminControl();

private slots:
    void on_adminControl_destroyed();

    void on_LogoutButton_clicked();

    void on_CreateProject_clicked();

    void on_RunPPID_clicked();

    void on_EditProject_clicked();

private:
    Ui::adminControl *ui;
    QWidget *Window;
    std::string username;
    Project *projectHolder;
};

#endif // ADMINCONTROL_H
