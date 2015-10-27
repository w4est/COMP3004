#ifndef EDITPROJECT_H
#define EDITPROJECT_H

#include <QDialog>
#include "admincontrol.h"

namespace Ui {
class EditProject;
}

class EditProject : public QDialog
{
    Q_OBJECT

public:
    explicit EditProject(QWidget *parent = 0, int _x = 150, int _y = 50, QString _username = "");
    ~EditProject();

private slots:
    void on_EditProject_destroyed();

    void on_BackButton_clicked();

private:
    Ui::EditProject *ui;
    QWidget *Window;
};

#endif // EDITPROJECT_H
