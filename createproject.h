#ifndef CREATEPROJECT_H
#define CREATEPROJECT_H

#include <QDialog>
#include "admincontrol.h"
#include "createproject2.h"

namespace Ui {
class CreateProject;
}

class CreateProject : public QDialog
{
    Q_OBJECT

public:
    explicit CreateProject(QWidget *parent = 0, int _x = 150, int _y = 50, QString _username = "");
    CreateProject(QWidget*,int, int, QString, QString, QString);
    ~CreateProject();

private slots:
    void on_BackButton_clicked();
    void on_CreateProject_destroyed();

    void on_NextButton_clicked();

private:
    Ui::CreateProject *ui;
    std::string projectDescription;
    std::string projectName;
    std::string username;
    QWidget *Window;
};

#endif // CREATEPROJECT_H



