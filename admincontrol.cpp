#include "admincontrol.h"
#include "ui_admincontrol.h"



adminControl::adminControl(QWidget *parent, int _x, int _y, QString _username) :
    QDialog(parent),
    ui(new Ui::adminControl)
{
    Window = parent;
    this->move(_x,_y-28);
    ui->setupUi(this);
    username = _username.toStdString(); //Set username




}

adminControl::~adminControl()
{
    delete ui;
}

void adminControl::on_adminControl_destroyed()
{
    delete(this);
}

/*
 * Go back to login, create login once again
 * Destroy self.
 *
 * */
void adminControl::on_LogoutButton_clicked()
{
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new Login(Window, childPos.x(), childPos.y());
    Window->show();
    delete(this);
}

void adminControl::on_CreateProject_clicked()
{
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new CreateProject(Window, childPos.x(), childPos.y(), username.c_str());
    Window->show();
    delete(this);
}