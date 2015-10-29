#ifndef CREATEPROJECT_H
#define CREATEPROJECT_H

#include <QDialog>
#include "AdminControl.h"
#include "createproject2.h"

class AdminControl;

namespace Ui {
class CreateProject;
}

class CreateProject : public QDialog
{
    Q_OBJECT

public:
    explicit CreateProject(AdminControl* _control, QWidget *parent = 0, int _x = 150, int _y = 50, QString _username = "");
    CreateProject(AdminControl* _control, QWidget*,int, int, QString, QString, QString);
    ~CreateProject();

private slots:
    void on_BackButton_clicked();
    void on_CreateProject_destroyed();

    void on_NextButton_clicked();

private:
    Ui::CreateProject *ui;
    QWidget *Window;
    AdminControl* control;

    std::string projectDescription;
    std::string projectName;
    std::string username;
};

#endif // CREATEPROJECT_H



