#include "editproject.h"
#include "ui_editproject.h"

EditProject::EditProject(AdminControl *_control, QWidget *parent, int _x, int _y):
    QDialog(parent),
    ui(new Ui::EditProject)
{
    //Create the window
    Window = parent;
    control = _control;

    this->move(_x,_y-28);
    string title = "Edit: " + control->getSelectedProject()->getProjectName();

    ui->setupUi(this);
    this->setWindowTitle(title.c_str());
    buildPage();
}

EditProject::~EditProject()
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

void EditProject::reject()
{
    this->deleteLater();
    control->shutdown();
}

void EditProject::on_EditProject_destroyed()
{
    this->deleteLater();
}

void EditProject::on_BackButton_clicked()
{
    //make next window
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new AdminView(control, Window, childPos.x(), childPos.y());
    Window->show();
    this->deleteLater();
}

void EditProject::buildPage()
{
    vector<Qualification*> qualList;
    vector<pair<int, int>> projQualList;

    qualList = control->getQualList();
    projQualList = control->getSelectedProject()->getQualifications();

    widget = new QWidget();

    layout = new QVBoxLayout();

    for(unsigned i = 0; i < qualList.size(); i++)
    {
        projectFrame* frame = new projectFrame(control, Window);


        frame->setDescription(qualList.at(i)->getAdminDescription().c_str());

        bool grade = false;
        if(qualList.at(i)->getType() == 3){
            grade = true;
            frame->setGrade(-7);
        }

        for(unsigned j = 0; j < projQualList.size(); j++){
            if(int(i) == projQualList.at(j).first){
                frame->setChecked();
                if(grade){
                    frame->setGrade(projQualList.at(j).second);
                }
            }
        }
        frame->setId(i);
        frameList.push_back(frame);
        layout->addWidget(frame);
    }

    widget->setLayout(layout);

    scrollBoxLayout = new QVBoxLayout();


    ui->scrollArea->setWidget(widget);
    ui->scrollArea->setLayout(scrollBoxLayout);
    ui->projectDescEdit->setText(control->getSelectedProject()->getProjectDescription().c_str());
}

void EditProject::setNewDescription()
{
    for(unsigned int i = 0; i < frameList.size(); i++)
    {
        if(frameList.at(i) == control->getCurrentFrame()){
            ui->qualDesc->setText(control->getQualList().at(i)->getAdminDescription().c_str());
        }
    }
}

void EditProject::mouseReleaseEvent(QMouseEvent *_event)
{
    if(_event){}
    setNewDescription();
}

void EditProject::on_SaveButton_clicked()
{
    Project* temp = control->getSelectedProject();
    temp->setProjectDescription(ui->projectDescEdit->toPlainText().toStdString());

    vector<pair<int, int>> tm;
    for(unsigned int i = 0; i < frameList.size(); i++)
    {
        if(frameList.at(i)->isChecked())
        {
            tm.push_back(make_pair<int, int>(frameList.at(i)->getId(), frameList.at(i)->getGrade()));
        }
    }

    temp->setQualifications(tm);

    control->saveProject();


    //QMessageBox::StandardButton reply;
      /*reply =*/QMessageBox::information(this, "Save Complete", "Project Saved" ,
                                    QMessageBox::Ok);

    on_BackButton_clicked();
}
