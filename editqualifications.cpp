#include "editqualifications.h"
#include "ui_editqualifications.h"
#include "register.h"

EditQualifications::EditQualifications(QWidget *parent, int _x, int _y, QString _username) :
    QDialog(parent),
    ui(new Ui::EditQualifications)
{
    Window = parent;
    validUsername = _username;

    this->move(_x, _y);

    ui->setupUi(this);
}

EditQualifications::~EditQualifications()
{
    delete ui;
}

void EditQualifications::on_EditQualifications_destroyed()
{
    delete(this);
}

void EditQualifications::reject()
{
    control.unregisterTempUsername(validUsername.toStdString());
    QDialog::reject();
}

void EditQualifications::on_ContinueButton_clicked()
{

}

void EditQualifications::on_BackButton_clicked()
{
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new Register(Window, childPos.x(), childPos.y(), validUsername);
    Window->show();
    control.unregisterTempUsername(validUsername.toStdString());
    delete(this);
}
