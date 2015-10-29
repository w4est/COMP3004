#include "runppid.h"
#include "ui_runppid.h"

RunPPID::RunPPID(AdminControl* _control, QWidget *parent, int _x, int _y, QString _projectName) :
    QDialog(parent),
    ui(new Ui::RunPPID)
{
    Window = parent;
    control = _control;

    this->move(_x,_y-28);


    ui->setupUi(this);
    ui->ProjectName->setText(_projectName);
}

RunPPID::~RunPPID()
{
    delete ui;
}

void RunPPID::on_RunPPID_destroyed()
{
    delete(this);
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
    //set group size to arg1
}

void RunPPID::on_BackButton_clicked()
{
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new AdminView(control, Window, childPos.x(), childPos.y());
    Window->show();
    delete(this);
}
