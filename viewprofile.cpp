#include "viewprofile.h"
#include "ui_viewprofile.h"

ViewProfile::ViewProfile(QWidget *parent, int _x, int _y, QString _username) :
    QDialog(parent),
    ui(new Ui::ViewProfile)
{
    Window = parent;

    this->move(_x, _y - 28);

    ui->setupUi(this);

}

ViewProfile::~ViewProfile()
{
    delete ui;
}





void ViewProfile::on_ViewProfile_destroyed()
{
    delete(this); //Make sure the pointer is destroyed upon ending the program
}

//Go back! Pass container to new window, and delete self.
void ViewProfile::on_BackButton_clicked()
{
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new Login(Window, childPos.x(), childPos.y());
    Window->show();
    delete(this);
}
