#include "editproject.h"
#include "ui_editproject.h"

EditProject::EditProject(AdminControl *_control, QWidget *parent, int _x, int _y, QString _username):
    QDialog(parent),
    ui(new Ui::EditProject)
{
    //Create the window
    Window = parent;
    control = _control;

    this->move(_x,_y-28);
    ui->setupUi(this);

    buildPage();
}

EditProject::~EditProject()
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

void EditProject::on_EditProject_destroyed()
{
    delete(this);
}

void EditProject::on_BackButton_clicked()
{
    //make next window
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new AdminView(control, Window, childPos.x(), childPos.y());
    Window->show();
    delete(this);
}

void EditProject::buildPage()
{
    vector<Qualification*> qualList;
    vector<pair<int, int>> projQualList;

    qualList = control->getQualList();
    projQualList = control->getSelectedProject()->getQualifications();

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

        for(unsigned j = 0; j < projQualList.size(); j++){
            if(int(i) == projQualList.at(j).first){
                cout << "checked" << endl;
                frame->setChecked();
            }
        }
        layout->addWidget(frame);
    }

    temp = 0;
    widget->setLayout(layout);

    scrollBoxLayout = new QVBoxLayout();
    //scrollBoxLayout->setSpacing(25);


    ui->scrollArea->setWidget(widget);
    ui->scrollArea->setLayout(scrollBoxLayout);
    ui->projectDescEdit->setText(control->getSelectedProject()->getProjectDescription().c_str());
}

void EditProject::setNewDescription()
{
    unsigned int o = -1;

    for(unsigned int i = 0; i < frameList.size(); i++)
    {
        if(frameList.at(i) == control->getCurrentFrame()){
            ui->qualDesc->setText(control->getQualList().at(i)->getAdminDescription().c_str());
        }
    }
}

void EditProject::mouseReleaseEvent(QMouseEvent *_event)
{
    std::cout << "edit" << std::endl;
    setNewDescription();
}
