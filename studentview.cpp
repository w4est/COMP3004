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

/*
 * Make sure that the form is deleted when forcefully closed
 *
 *
 * */
void StudentView::on_StudentView_destroyed()
{
    this->deleteLater();
}

void StudentView::reject()
{
    this->deleteLater();
    control->shutdown();
}

/*
 * Open StudetnViewProject
 * Queue for Deletion
 *StudentView
 * */
void StudentView::on_ViewProjectButton_clicked()
{
    control->ViewProject(Window,this->x(),this->y());
    this->deleteLater();
}

/*
 * Open StudentViewProfile
 * Queue for deletion.
 * */

void StudentView::on_ViewProfileButton_clicked()
{


    control->ViewProfile(Window,this->x(),this->y());
    this->deleteLater();

}

/*
 * Logout
 * use StudentControl to logout.
 * Queue for deletion
 * */

void StudentView::on_LogoutButton_clicked()
{
    control->logout(new QPoint(this->mapToGlobal(QPoint(0,0))));
    this->deleteLater();
}



