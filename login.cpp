#include "login.h"
#include "ui_login.h"
#include "register.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    Window = parent;
    ui->setupUi(this);
    ui->UsernameBox->setPlaceholderText("Enter Username...");
}



Login::~Login()
{
    delete ui;
}

void Login::on_LoginButton_clicked()
{
    std::string name = ui->UsernameBox->text().toStdString();

    if(control.validUsername(name)){
        //TODO: CHANGE THIS LATER
        ui->UsernameBox->setText("VALID");
    }
    else{
        //CHANGE THIS ALSO
        ui->UsernameBox->setText("WRONG");
    }
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
