#include "studentviewproject.h"
#include "ui_studentviewproject.h"
#include "studentview.h"

studentViewProject::studentViewProject(StudentControl *_control, QWidget *parent, int _x, int _y) :
    QDialog(parent),
    ui(new Ui::studentViewProject)
{
    Window = parent;
    control = _control;

    this->move(_x, _y -28);
    ui->setupUi(this);

    buildProjectList();
}

studentViewProject::~studentViewProject()
{
    control = 0;
    selected = 0;

    ui->ProjectList->clear();

    delete ui;
}

void studentViewProject::on_BackButton_clicked()
{
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new StudentView(control, Window, childPos.x(), childPos.y());
    Window->show();
    this->deleteLater();
}

void studentViewProject::on_JoinButton_clicked()
{
    //save later TODO
}

void studentViewProject::reject()
{
    this->deleteLater();
    control->shutdown();
}

void studentViewProject::on_ProjectList_itemClicked(QListWidgetItem *item)
{
    ui->ProjectList->clear();


    selected = control->getProject(-1, item->text().toStdString());
    control->setSelectedProject(selected);
    vector<string> t = selected->getStudents();

    for(unsigned int i = 0; i < t.size(); i++)
    {
        QListWidgetItem* s = new QListWidgetItem(t.at(i).c_str());

        ui->ProjectList->addItem(s);
    }
}

void studentViewProject::buildProjectList()
{
    for(int i = 0; i < control->getListSize(); i++){
        Project* tm = control->getProject(i);

        if(tm){
            if(tm->getOwner().compare(control->getLoggedUser()->getUsername()) == 0){
                QListWidgetItem* t = new QListWidgetItem(tm->getProjectName().c_str());
                //wList.push_back(t);

                ui->ProjectList->addItem(t);
            }
        }
        tm = 0;
    }
}
