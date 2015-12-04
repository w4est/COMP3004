#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include <QDialog>
#include "StudentControl.h"


namespace Ui {
class StudentView;
}

class StudentView : public QDialog
{
    Q_OBJECT

public:
    explicit StudentView(StudentControl *_control, QWidget *parent = 0, int _x = 150, int _y = 50);
    ~StudentView();

private slots:
    void on_StudentView_destroyed();

    void on_ViewProjectButton_clicked();

    void on_ViewProfileButton_clicked();

    void on_LogoutButton_clicked();

    void reject();


private:
    Ui::StudentView *ui;
    QWidget *Window;
    StudentControl *control;

};

#endif // STUDENTVIEW_H
