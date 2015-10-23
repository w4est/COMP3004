#include "login.h"
#include "ui_login.h"
#include "register.h"

Login::Login(QWidget *parent, int _x, int _y) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    Window = parent;

    this->move(_x, _y - 28);

    ui->setupUi(this);
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
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new Register(Window, childPos.x(), childPos.y());
    Window->show();
    delete(this);
}

void Login::on_Login_destroyed()
{
    delete(this);
}
