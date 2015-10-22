#include "login.h"
#include "ui_login.h"
#include "register.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    Window = parent;
    ui->setupUi(this);
}



Login::~Login()
{
    delete ui;
}

void Login::on_LoginButton_clicked()
{
    ui->UsernameBox->setText("HELLO");
}

void Login::on_RegisterButton_clicked()
{
    Window = new Register(Window);
    Window->show();
    delete(this);
}

void Login::on_Login_destroyed()
{
    delete(this);
}
