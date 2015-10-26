#include "register.h"
#include "ui_register.h"
#include "login.h"
#include "editqualifications.h"


Register::Register(QWidget *parent, int _x, int _y, QString _username) :
    QDialog(parent),
    ui(new Ui::Register)
{
    Window = parent;

    this->move(_x, _y - 28);

    ui->setupUi(this);
    ui->UsernameEdit->setText(_username);
    this->on_CheckButton_clicked();
}

Register::~Register()
{
    delete ui;
}

void Register::on_BackButton_clicked()
{
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new Login(Window, childPos.x(), childPos.y());
    Window->show();
    delete(this);
}

void Register::on_Register_destroyed()
{
    delete(this);
}

void Register::on_ContinueButton_clicked()
{
    //Check admin, then check user.
    control = new Login_Control("admin_list.txt");
    bool comp = control->validUsername(ui->UsernameEdit->text().toStdString());
    delete(control);

    control = new Login_Control("username_list.txt");
    bool comp2 = control->registerTempUsername(ui->UsernameEdit->text().toStdString());
    delete(control);

    std::cout << comp << comp2 << std::endl;
   if(!comp && comp2){
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new EditQualifications(Window, childPos.x(), childPos.y(), ui->UsernameEdit->text());
    Window->show();
    delete(this);
   }
   else{
       ui->ContinueButton->setEnabled(false);
       ui->Warning_Label->setText("Unavailable");
       ui->UsernameEdit->setStyleSheet("QLineEdit { background: rgb(255, 102, 102); selection-background-color: rgb(0, 0, 0)}");

   }
}

/*
 * Check for username availability
 *
 * Create a second login control to check the admin list,
 * and check the username list with the existing.
 *
 * Make sure to cleanup.
 *
 * */


void Register::on_CheckButton_clicked()
{
    std::string name = ui->UsernameEdit->text().toStdString();

    Login_Control *control2 = new Login_Control("admin_list.txt");



    control = new Login_Control("username_list.txt");
    if(name.compare("") == 0){

    }
    else if(!control->validUsername(name) && !control2->validUsername(name)){
        ui->ContinueButton->setEnabled(true);
        ui->Warning_Label->setText("Available");
        ui->UsernameEdit->setStyleSheet("QLineEdit { background: rgb(0, 204, 51); selection-background-color: rgb(0, 0, 0)}");
    }

    else{
       ui->Warning_Label->setText("Unavailable");
       ui->UsernameEdit->setStyleSheet("QLineEdit { background: rgb(255, 102, 102); selection-background-color: rgb(0, 0, 0)}");
    }
    delete(control);
    delete(control2);
}

void Register::on_UsernameEdit_textEdited(const QString &arg1)
{
    QString junk = arg1;
    junk = "";

    ui->ContinueButton->setEnabled(false);
    ui->Warning_Label->setText(junk);
    ui->UsernameEdit->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); selection-background-color: default}");

}
