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
    string title = "Create Project part 2";

    ui->setupUi(this);
    this->setWindowTitle(title.c_str());

    buildPage();
}

CreateProject2::~CreateProject2()
{
    while(!frameList.empty())
    {
        projectFrame* temp = frameList.back();
        temp->deleteLater();
        frameList.pop_back();
    }
    layout->deleteLater();
    widget->deleteLater();
    scrollBoxLayout->deleteLater();

    delete ui;
}

void CreateProject2::reject()
{
    this->deleteLater();
    control->shutdown();
}

void CreateProject2::on_BackButton_clicked(){

    control->setCurrentFrame(0);
    //Go back
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new CreateProject(control, Window, childPos.x(), childPos.y(), username.c_str(), projectName.c_str(),projectDescription.c_str()); //Pass back parameters
    Window->show();
   this->deleteLater();

}


void CreateProject2::on_CreateProject2_destroyed()
{
    this->deleteLater();
}

void CreateProject2::on_CreateButton_clicked()
{
    Project* tm = new Project();
    tm->setOwner(username);
    tm->setProjectName(projectName);
    tm->setProjectDescription(projectDescription);

    vector<pair<int, int>> qual;
    for(unsigned int i = 0; i < frameList.size(); i++)
    {
        if(frameList.at(i)->isChecked()){
            qual.push_back(make_pair<int, int>(frameList.at(i)->getId(), frameList.at(i)->getGrade()));
        }
    }

    tm->setQualifications(qual);
    control->setCurrentFrame(0);
    control->createProject(tm);
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new AdminView(control, Window, childPos.x(), childPos.y());
    Window->show();
    this->deleteLater();
}

void CreateProject2::buildPage()
{
    vector<Qualification*> qualList;
    vector<pair<int, int>> projQualList;

    qualList = control->getQualList();

    widget = new QWidget();

    layout = new QVBoxLayout();

    for(unsigned i = 0; i < qualList.size(); i++)
    {
        projectFrame* frame = new projectFrame(control, Window);

        frameList.push_back(frame);
        frame->setDescription(qualList.at(i)->getAdminDescription().c_str());
        frame->setId(qualList.at(i)->getId());

        if(qualList.at(i)->getType() == 3){
            frame->setGrade(-7);
        }

        frame->setChecked();
        layout->addWidget(frame);
    }

    widget->setLayout(layout);

    scrollBoxLayout = new QVBoxLayout();
    //scrollBoxLayout->setSpacing(25);

    ui->scrollArea->setWidget(widget);
    ui->scrollArea->setLayout(scrollBoxLayout);

}

void CreateProject2::setNewDescription()
{
    for(unsigned int i = 0; i < frameList.size(); i++)
    {
        if(frameList.at(i) == control->getCurrentFrame()){
            ui->DescriptionLabel->setText(control->getQualList().at(i)->getAdminDescription().c_str());
        }
    }
}

void CreateProject2::mouseReleaseEvent(QMouseEvent *_event)
{
    if(_event){}
    setNewDescription();
}
