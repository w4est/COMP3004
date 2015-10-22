#include "register.h"
#include "ui_register.h"
#include "login.h"


Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    Window = parent;
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_BackButton_clicked()
{
    Window = new Login(Window);
    Window->show();
    delete(this);
}

void Register::on_Register_destroyed()
{
    delete(this);
}
