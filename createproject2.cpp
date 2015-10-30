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

    buildPage();
}


void CreateProject2::on_BackButton_clicked(){

    control->setCurrentFrame(0);
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
    while(!frameList.empty())
    {
        delete frameList.back();
        frameList.pop_back();
    }
    delete layout;
    delete widget;
    delete scrollBoxLayout;

    delete ui;
}

void CreateProject2::on_CreateButton_clicked()
{
    Project* tm = new Project();
    cout << username << endl;
    tm->setOwner(username);
    tm->setProjectName(projectName);
    tm->setProjectDescription(projectDescription);

    control->setCurrentFrame(0);
    control->createProject(tm);
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new AdminView(control, Window, childPos.x(), childPos.y());
    Window->show();
    delete(this);
}

void CreateProject2::buildPage()
{
    vector<Qualification*> qualList;
    vector<pair<int, int>> projQualList;

    qualList = control->getQualList();

    QWidget *form;

    widget = new QWidget();

    layout = new QVBoxLayout();

     Qualification* temp;

    for(unsigned i = 0; i < qualList.size(); i++)
    {
        temp = qualList[i];

        projectFrame* frame = new projectFrame(control, Window);

        frameList.push_back(frame);
        frame->setDescription(qualList.at(i)->getAdminDescription().c_str());

        frame->setChecked();
        layout->addWidget(frame);
    }

    temp = 0;
    widget->setLayout(layout);

    scrollBoxLayout = new QVBoxLayout();
    //scrollBoxLayout->setSpacing(25);

    ui->scrollArea->setWidget(widget);
    ui->scrollArea->setLayout(scrollBoxLayout);

}

void CreateProject2::setNewDescription()
{
    unsigned int o = -1;

    for(unsigned int i = 0; i < frameList.size(); i++)
    {
        if(frameList.at(i) == control->getCurrentFrame()){
            ui->DescriptionLabel->setText(control->getQualList().at(i)->getAdminDescription().c_str());
        }
    }
}

void CreateProject2::mouseReleaseEvent(QMouseEvent *_event)
{
    std::cout << "createProject2" << std::endl;
    setNewDescription();
}
