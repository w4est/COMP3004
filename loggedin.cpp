#include "loggedin.h"
#include "ui_loggedin.h"

LoggedIn::LoggedIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoggedIn)
{
    ui->setupUi(this);
}

LoggedIn::~LoggedIn()
{
    delete ui;
}

void LoggedIn::on_LoggedIn_destroyed()
{
    delete (this);
}
