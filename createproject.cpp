#include "createproject.h"
#include "ui_createproject.h"

CreateProject::CreateProject(AdminControl* _control, QWidget *parent, int _x, int _y, QString _username) :
    QDialog(parent),
    ui(new Ui::CreateProject)
{
    Window = parent;
    control = _control;

    username = _username.toStdString();

    this->move(_x,_y-28);
    string title = "Create Project part 1";

    ui->setupUi(this);
    this->setWindowTitle(title.c_str());
}

CreateProject::CreateProject(AdminControl* _control, QWidget *parent, int _x, int _y, QString _username, QString Name, QString Description) :
    QDialog(parent),
    ui(new Ui::CreateProject)
{
    //Construct with the previous values
    Window = parent;
    control = _control;

    this->move(_x,_y-28);
    ui->setupUi(this);

    //Save the values.
    projectDescription = Description.toStdString();
    projectName = Name.toStdString();
    username = _username.toStdString(); //Pass the current user.

    ui->NameEdit->setText(projectName.c_str());
    ui->DescriptionEdit->setText(projectDescription.c_str());
}

CreateProject::~CreateProject()
{
    delete ui;
}

void CreateProject::reject()
{
    this->deleteLater();
    control->shutdown();
}

void CreateProject::on_CreateProject_destroyed()
{
    this->deleteLater();
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

    string cleaner = projectName;
    bool isClean = false;

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
        QMessageBox::information(this, "Alert", "Project Name Cannot Be Empty" ,
                                                QMessageBox::Ok);
        return;
    }

    Project* tm;
    for(int i = 0; i < control->getListSize(); i++){
        Project* tm = control->getProject(i);
        if (tm->getProjectName().compare(projectName) == 0)
        {
            QMessageBox::information(this, "Alert", "Sorry, This Project name is already taken" ,
                                                    QMessageBox::Ok);
            return;
        }
    }


    //make next window
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = control->getMParent()->GetForm(9,control,childPos.x(), childPos.y(), username.c_str(), projectName.c_str(), projectDescription.c_str());
            //new CreateProject2(control, Window, childPos.x(), childPos.y(), username.c_str(), projectName.c_str(), projectDescription.c_str());
    //Window->show();
    this->deleteLater();
}

void CreateProject::on_BackButton_clicked()
{
    //Go back
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = control->getMParent()->GetForm(7,control,childPos.x(), childPos.y());
            //new AdminView(control, Window, childPos.x(), childPos.y());
    //Window->show();
    this->deleteLater();
}
