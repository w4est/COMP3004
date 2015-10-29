#include "createproject2.h"
#include "ui_createproject2.h"

CreateProject2::CreateProject2(AdminControl* _control, QWidget *parent, int _x, int _y, QString _username, QString Name, QString Description) :
    QDialog(parent),
    ui(new Ui::CreateProject2)
{
    Window = parent;
    control = _control;

    this->move(_x,_y-28);

    //Save the values.
    projectDescription = Description.toStdString();
    projectName = Name.toStdString();
    username = _username.toStdString(); //Pass the current user.

    ui->setupUi(this);
}


void CreateProject2::on_BackButton_clicked(){

    //Go back
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new CreateProject(control, Window, childPos.x(), childPos.y(), username.c_str(), projectName.c_str(),projectDescription.c_str()); //Pass back parameters
    Window->show();
    delete(this);

}


void CreateProject2::on_CreateProject2_destroyed()
{
    delete(this);
}


CreateProject2::~CreateProject2()
{
    delete ui;
}

void CreateProject2::on_CreateButton_clicked()
{
    Project* tm = new Project();
    cout << username << endl;
    tm->setOwner(username);
    tm->setProjectName(projectName);
    tm->setProjectDescription(projectDescription);


    control->createProject(tm);
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new AdminView(control, Window, childPos.x(), childPos.y());
    Window->show();
    delete(this);
}
