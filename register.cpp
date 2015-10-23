#include "register.h"
#include "ui_register.h"
#include "login.h"


Register::Register(QWidget *parent, int _x, int _y) :
    QDialog(parent),
    ui(new Ui::Register)
{
    Window = parent;

    this->move(_x, _y);
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_BackButton_clicked()
{
    Window = new Login(Window, this->pos().x(), this->pos().y());
    Window->show();
    delete(this);
}

void Register::on_Register_destroyed()
{
    delete(this);
}
