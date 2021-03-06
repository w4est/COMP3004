#include "register.h"
#include "ui_register.h"
#include "login.h"
#include "editqualifications.h"


Register::Register(LoginControl *_control, QWidget *parent, int _x, int _y, QString _username) :
    QDialog(parent),
    ui(new Ui::Register)
{
    Window = parent;
    control = _control;
    preventReturn_back = false;

    if(_username.isEmpty())
    {
        firstLoad = true;
    }
    else{
        firstLoad = false;
    }

    this->move(_x, _y - 28);

    ui->setupUi(this);
    ui->UsernameEdit->setText(_username);
    this->on_CheckButton_clicked();
}

Register::~Register()
{
    delete ui;
}

void Register::reject()
{
    this->deleteLater();
    control->shutdown();
}

/*
 * Go back to login page,
 * Destroy self after.
 *
 * */
void Register::on_BackButton_clicked()
{
    if(preventReturn_back){
        preventReturn_back = false;
        return;
    }

    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = control->getMParent()->GetForm(0,control,childPos.x(), childPos.y());
            //new Login(control, Window, childPos.x(), childPos.y());
    //Window->show();
    this->deleteLater();
}

void Register::on_Register_destroyed()
{
    this->deleteLater();
}

void Register::on_ContinueButton_clicked()
{
    bool comp = control->registerTempUser(ui->UsernameEdit->text().toStdString());

   if(comp){
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = control->getMParent()->GetForm(2,control,childPos.x(), childPos.y(), ui->UsernameEdit->text(),0);
            //new EditQualifications(control, Window, childPos.x(), childPos.y(), ui->UsernameEdit->text());
    //Window->show();
    this->deleteLater();
   }
   else{
       //Warn user otherwise
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

    string cleaner = name;
    bool isClean = false;

    if(!firstLoad){
        while(!isClean)
        {
            size_t s = cleaner.find_first_of(' ');

            if(s == std::string::npos)
            {
              isClean = true;
            }
            else{
                cleaner.erase(s, s+1);
            }
        }

        if(cleaner.size() == 0){
            QMessageBox::information(this, "Alert", "Name Cannot Be Empty" ,
                                                    QMessageBox::Ok);
            return;
        }
    }
    else{
        firstLoad = false;
    }

    if(name.compare("") == 0){

    }
    else if(!control->userExists(name)){
        ui->ContinueButton->setEnabled(true);
        ui->Warning_Label->setText("Available");
        ui->UsernameEdit->setStyleSheet("QLineEdit { background: rgb(0, 204, 51); selection-background-color: rgb(0, 0, 0)}");
    }

    else{
       ui->Warning_Label->setText("Unavailable");
       ui->UsernameEdit->setStyleSheet("QLineEdit { background: rgb(255, 102, 102); selection-background-color: rgb(0, 0, 0)}");
    }
}

//When editing text, change background colour.
void Register::on_UsernameEdit_textEdited(const QString &arg1)
{
    QString junk = arg1;
    junk = "";


    ui->ContinueButton->setEnabled(false);
    ui->Warning_Label->setText(junk);
    ui->UsernameEdit->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); selection-background-color: default}");

}

void Register::on_UsernameEdit_returnPressed()
{
    preventReturn_back = true;
    this->on_CheckButton_clicked();
}
