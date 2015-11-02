#include "studentview.h"
#include "ui_studentview.h"

StudentView::StudentView(StudentControl *_control, QWidget *parent, int _x, int _y) :
    QDialog(parent),
    ui(new Ui::StudentView)
{
    Window = parent;
    control = _control;

    this->move(_x, _y - 28);

    ui->setupUi(this);
}

StudentView::~StudentView()
{
    delete ui;
}

void StudentView::on_StudentView_destroyed()
{
    this->deleteLater();
}


/*
 * Open StudetnViewProject
 *
 *
 * */
void StudentView::on_ViewProjectButton_clicked()
{

}

/*
 * Open StudentViewProfile
 *
 * */

void StudentView::on_ViewProfileButton_clicked()
{

}

/*
 * Logout
 *
 *
 * */

void StudentView::on_LogoutButton_clicked()
{

}
