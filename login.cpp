#include "login.h"
#include "ui_login.h"
#include "register.h"


Login::Login(LoginControl *_control, QWidget *parent, int _x, int _y) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    Window = parent;
    control = _control;

    this->move(_x, _y - 28);

    ui->setupUi(this);
}

Login::~Login()
{
    control = 0;
    delete ui;
}

void Login::reject()
{
    delete(this);
}

void Login::on_LoginButton_clicked()
{
    std::string name = ui->UsernameBox->text().toStdString();

    if(control->userExists(name)) // if !(0) [-1 or 1] then it exists, 1 == Student, -1 == Admin
    {
        std::string Message = "Hello " + name;
        QMessageBox::StandardButton reply;
          reply = QMessageBox::information(this, "Welcome", Message.c_str() ,
                                        QMessageBox::Ok);

        control->loginUser(name, new QPoint(this->mapToGlobal(QPoint(0,0))));
        delete(this);
    }
    else
    {
        ui->Warning_Label->setText("Incorrect");
        ui->UsernameBox->setStyleSheet("QLineEdit { background: rgb(255, 102, 102); selection-background-color: rgb(0, 0, 0)}");
    }
}

void Login::on_RegisterButton_clicked()
{
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new Register(control, 0, childPos.x(), childPos.y());
    Window->show();
    delete(this);

}

void Login::on_Login_destroyed()
{
    delete(this);
}

void Login::reEnable()
{
    this->setEnabled(true);
}

void Login::on_UsernameBox_textEdited(const QString &arg1)
{
    QString junk = arg1;
    junk = "";

    ui->Warning_Label->setText(junk);
    ui->UsernameBox->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); selection-background-color: default}");
}

void Login::on_UsernameBox_returnPressed()
{
    on_LoginButton_clicked();
}
