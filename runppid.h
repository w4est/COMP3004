#ifndef RUNPPID_H
#define RUNPPID_H

#include <QDialog>
#include <QWidget>
#include "AdminControl.h"
#include "adminview.h"

class AdminControl;

namespace Ui {
class RunPPID;
}

class RunPPID : public QDialog
{
    Q_OBJECT

public:
    explicit RunPPID(AdminControl* _control, QWidget *parent = 0, int _x = 150, int _y = 50, QString _projectName = "");
    ~RunPPID();

private slots:
    void on_RunPPID_destroyed();

    void on_comboBox_activated(int index);

    void on_groupSize_valueChanged(int arg1);


    void on_BackButton_clicked();

private:
    Ui::RunPPID *ui;
    QWidget *Window;
    AdminControl* control;
};

#endif // RUNPPID_H
