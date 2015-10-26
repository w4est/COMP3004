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
    control = new Login_Control("admin_list.txt");
    std::string name = ui->UsernameBox->text().toStdString();
    if(control->validUsername(name))
    {
        delete(control); //Make sure it doesnt' go crazy.


        QPoint childPos = this->mapToGlobal(QPoint(0,0));
        Window = new adminControl(Window, childPos.x(), childPos.y(), ui->UsernameBox->text());
        Window->show();
        delete(this);


    }
    else{
        delete(control);



    control = new Login_Control("username_list.txt");

        if(control->validUsername(name)){
            //TODO: CHANGE THIS LATER
            ui->UsernameBox->setText("VALID");
        }
        else{
            //CHANGE THIS ALSO
            ui->UsernameBox->setText("WRONG");
        }
        delete (control);
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
