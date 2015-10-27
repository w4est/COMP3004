#include "admincontrol.h"
#include "ui_admincontrol.h"



adminControl::adminControl(QWidget *parent, int _x, int _y, QString _username) :
    QDialog(parent),
    ui(new Ui::adminControl)
{
    Window = parent;
    this->move(_x,_y-28);
    ui->setupUi(this);
    username = _username.toStdString(); //Set username
    model = new QStringlistModel(this);
    QStringList List;
    List << "Test1" << "Test2";
            model->setStringList(List);
    ui->ProjectList->setModel(model);
}

adminControl::~adminControl()
{
    delete ui;
}

void adminControl::on_adminControl_destroyed()
{
    delete(this);
}

/*
 * Go back to login, create login once again
 * Destroy self.
 *
 * */
void adminControl::on_LogoutButton_clicked()
{
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new Login(Window, childPos.x(), childPos.y());
    Window->show();
    delete(this);
}

/*
 * Create a new Project
 *
 * */
void adminControl::on_CreateProject_clicked()
{
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new CreateProject(Window, childPos.x(), childPos.y(), username.c_str());
    Window->show();
    delete(this);
}

/*
 * Run the PPID
 *
 * */

void adminControl::on_RunPPID_clicked()
{

    //Get selected project. If multiple are selected, take the highest.
    //ui->ProjectList->selectedItems();

    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new RunPPID(Window, childPos.x(), childPos.y(), username.c_str());
    Window->show();
    delete(this);


}

void adminControl::on_EditProject_clicked()
{
    QListWidgetItem currentList = ui->ProjectList->currentItem();
    Project currentProject = (Project)currentList.;


    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new EditProject(Window, childPos.x(), childPos.y(), currentProject);
    Window->show();
    delete(this);

}
