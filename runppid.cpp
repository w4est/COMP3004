#include "runppid.h"
#include "ui_runppid.h"
#include "resultswindow.h"

RunPPID::RunPPID(AdminControl* _control, QWidget *parent, int _x, int _y, QString _projectName) :
    QDialog(parent),
    ui(new Ui::RunPPID)
{
    Window = parent;
    control = _control;

    this->move(_x,_y-28);
    string title = "PPID Control";
    groupSize = 0;

    ui->setupUi(this);
    this->setWindowTitle(title.c_str());
    ui->ProjectName->setText(_projectName);
    ui->RunPPIDButton->setEnabled(true);
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
    else if(index == 1)
    {
        //project
    }
    else{
        //something
    }
}

void RunPPID::on_groupSize_valueChanged(int arg1)
{
    groupSize = arg1;
}

void RunPPID::on_BackButton_clicked()
{
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = control->getMParent()->GetForm(7,control,childPos.x(), childPos.y());
            //AdminView(control, Window, childPos.x(), childPos.y());
    //Window->show();
    this->deleteLater();
}

void RunPPID::on_RunPPIDButton_clicked()
{
    std::string Message = "We'd better turn back now.";
    //QMessageBox::StandardButton reply;
      /*reply = */QMessageBox::information(this, "Something Feels Errie...", Message.c_str() ,
                                    QMessageBox::Ok);

    std::vector<ProfileEntity*> nList;
    std::vector<std::string> sList = control->getSelectedProject()->getStudents();

    int size = sList.size();

    for(int i = 0; i < size; i++)
    {
        nList.push_back(control->getMParent()->getStorageAccess().getProfile(0, sList.at(i)));
    }
    testVector(nList);
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    QWidget *result = new ResultsWindow(0);
    result->show();

}

void RunPPID::testVector(std::vector<ProfileEntity *> & _test)
{
    for(int i = 0; i < _test.size(); i++)
    {
        ProfileEntity* temp = _test.at(i);
        cout <<  temp->getUsername() << endl;
    }
}
