#include "adminview.h"
#include "ui_adminview.h"
#include "QStringList"
#include "editproject.h"

AdminView::AdminView(AdminControl *_control, QWidget *parent, int _x, int _y) :
    QDialog(parent),
    ui(new Ui::AdminView)
{
    Window = parent;
    control = _control;

    this->move(_x, _y - 28);

    ui->setupUi(this);

    buildProjectList();
}

AdminView::~AdminView()
{
    control = 0;
    selected = 0;

    while(!sList.empty())
    {
        delete sList.back();
        sList.pop_back();
    }

    while(!wList.empty())
    {
        delete wList.back();
        wList.pop_back();
    }


    delete ui;
}

void AdminView::on_CreateProject_clicked()
{
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new CreateProject(control, Window, childPos.x(), childPos.y(), control->getLoggedUser()->getUsername().c_str());
    Window->show();
    //delete(projectHolder);
    delete(this);
}

void AdminView::on_LogoutButton_clicked()
{
    control->logout(new QPoint(this->mapToGlobal(QPoint(0,0))));
    delete(this);
}

void AdminView::on_RunPPID_clicked()
{
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new RunPPID(control, Window, childPos.x(), childPos.y(),  control->getLoggedUser()->getUsername().c_str());
    Window->show();

    delete(this);
}

void AdminView::on_EditProject_clicked()
{
    if(control->getSelectedProject()){
        QPoint childPos = this->mapToGlobal(QPoint(0,0));
        Window = new EditProject(control, Window, childPos.x(), childPos.y());
        Window->show();
        delete(this);
    }
}

void AdminView::on_AdminView_destroyed()
{
    delete(this);
}

/*USELESS*/
void AdminView::on_AdminView_rejected()
{
}

void AdminView::reject()
{
    delete(this);
}

void AdminView::buildProjectList()
{
    for(int i = 0; i < control->getListSize(); i++){
        Project* tm = control->getProject(i);

        if(tm){
            if(tm->getOwner().compare(control->getLoggedUser()->getUsername()) == 0){
                QListWidgetItem* t = new QListWidgetItem(tm->getProjectName().c_str());
                wList.push_back(t);

                ui->ProjectList->addItem(t);
            }
        }
    }
}

void AdminView::on_ProjectList_itemClicked(QListWidgetItem *item)
{
    while(!sList.empty())
    {
        delete sList.back();
        sList.pop_back();
    }


    selected = control->getProject(-1, item->text().toStdString());
    control->setSelectedProject(selected);
    vector<string> t = selected->getStudents();

    for(int i = 0; i < t.size(); i++)
    {
        QListWidgetItem* s = new QListWidgetItem(t.at(i).c_str());
        sList.push_back(s);

        ui->StudentList->addItem(s);
    }
}
