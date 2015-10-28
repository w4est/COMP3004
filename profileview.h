#ifndef PROFILEVIEW_H
#define PROFILEVIEW_H

#include <QDialog>
#include "StudentControl.h"

class StudentControl;

namespace Ui {
class ProfileView;
}

class ProfileView : public QDialog
{
    Q_OBJECT

public:
    explicit ProfileView(StudentControl *_control, QWidget *parent = 0, int _x = 150, int _y = 50);
    ~ProfileView();

private slots:
    void on_BackButton_clicked();

    void reject();

private:
    Ui::ProfileView *ui;
    QWidget *Window;

    StudentControl *control;
};

#endif // PROFILEVIEW_H
