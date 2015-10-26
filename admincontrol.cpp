#include "admincontrol.h"
#include "ui_admincontrol.h"
#include <QMessageBox>


adminControl::adminControl(QWidget *parent, int _x, int _y, QString _username) :
    QDialog(parent),
    ui(new Ui::adminControl)
{
    Window = parent;
    this->move(_x,_y-28);
    ui->setupUi(this);
    username = _username.toStdString(); //Set username

    std::string Message = "Hello " + username;
    std::cout << Message << std::endl;
    QMessageBox::StandardButton reply;
      reply = QMessageBox::information(this, "Welcome", Message.c_str() ,
                                    QMessageBox::Ok);



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
