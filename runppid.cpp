#include "runppid.h"
#include "ui_runppid.h"

RunPPID::RunPPID(AdminControl* _control, QWidget *parent, int _x, int _y, QString _projectName) :
    QDialog(parent),
    ui(new Ui::RunPPID)
{
    Window = parent;
    control = _control;

    this->move(_x,_y-28);
    string title = "PPID Control";

    ui->setupUi(this);
    this->setWindowTitle(title.c_str());
    ui->ProjectName->setText(_projectName);
    ui->RunPPIDButton->setEnabled(false);
}

RunPPID::~RunPPID()
{
    delete ui;
}

void RunPPID::reject()
{
    this->deleteLater();
    control->shutdown();
}

void RunPPID::on_RunPPID_destroyed()
{
    this->deleteLater();
}


void RunPPID::on_comboBox_activated(int index)
{
    if(index==0){
        //student
    }
    else{
        //project
    }
}

void RunPPID::on_groupSize_valueChanged(int arg1)
{
    if(arg1){}
    //set group size to arg1
}

void RunPPID::on_BackButton_clicked()
{
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new AdminView(control, Window, childPos.x(), childPos.y());
    Window->show();
    this->deleteLater();
}

void RunPPID::on_RunPPIDButton_clicked()
{
    std::string Message = "We'd better turn back now.";
    //QMessageBox::StandardButton reply;
      /*reply = */QMessageBox::information(this, "Something Feels Errie...", Message.c_str() ,
                                    QMessageBox::Ok);

}
