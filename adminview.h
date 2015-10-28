#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include <QDialog>
#include "AdminControl.h"

class AdminControl;

namespace Ui {
class AdminView;
}

class AdminView : public QDialog
{
    Q_OBJECT

public:
    explicit AdminView(AdminControl *_control, QWidget *parent = 0, int _x = 150, int _y = 50);
    ~AdminView();

private slots:
    void on_CreateProject_clicked();

    void on_LogoutButton_clicked();

    void on_RunPPID_clicked();

    void on_EditProject_clicked();

    void on_AdminView_destroyed();

    void on_AdminView_rejected();

    void reject();

private:
    Ui::AdminView *ui;
    QWidget *Window;

    AdminControl *control;
};

#endif // ADMINVIEW_H
