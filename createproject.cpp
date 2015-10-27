#include "createproject.h"
#include "ui_createproject.h"

CreateProject::CreateProject(QWidget *parent, int _x, int _y, QString _username) :
    QDialog(parent),
    ui(new Ui::CreateProject)
{
    Window = parent;
    this->move(_x,_y-28);
    ui->setupUi(this);

}

CreateProject::CreateProject(QWidget *parent, int _x, int _y, QString _username, QString Name, QString Description) :
    QDialog(parent),
    ui(new Ui::CreateProject)
{
    //Construct with the previous values
    Window = parent;
    this->move(_x,_y-28);
    ui->setupUi(this);

    //Save the values.
    projectDescription = Description.toStdString();
    projectName = Name.toStdString();
    username = _username.toStdString(); //Pass the current user.

    ui->NameEdit->setText(projectName.c_str());
    ui->DescriptionEdit->setText(projectDescription.c_str());
}

void CreateProject::on_CreateProject_destroyed()
{
    delete(this);
}


CreateProject::~CreateProject()
{
    delete ui;
}

/*
 * Next Button, pass description and text
 *
 * */
void CreateProject::on_NextButton_clicked()
{
    //Get input
    projectName = ui->NameEdit->text().toStdString();
    projectDescription = ui->DescriptionEdit->toPlainText().toStdString();

    //make next window
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new CreateProject2(Window, childPos.x(), childPos.y(), username.c_str(), projectName.c_str(), projectDescription.c_str());
    Window->show();
    delete(this);
}

void CreateProject::on_BackButton_clicked()
{
    //Go back
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new adminControl(Window, childPos.x(), childPos.y());
    Window->show();
    delete(this);
}