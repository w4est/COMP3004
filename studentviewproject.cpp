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

    string title = "Available Projects List";
    this->setWindowTitle(title.c_str());

    buildProjectList();
}

studentViewProject::~studentViewProject()
{
    control = 0;
    selected = 0;
    itemSelected = 0;

    ui->ProjectList->clear();

    delete ui;
}

void studentViewProject::on_BackButton_clicked()
{
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = control->getMParent()->GetForm(3,control,childPos.x(), childPos.y());
            //new StudentView(control, Window, childPos.x(), childPos.y());
    //Window->show();

    this->deleteLater();
}

void studentViewProject::on_JoinButton_clicked()
{
    vector<string> temp_list = selected->getStudents();
    bool isRegistered = false;
    string user = control->getLoggedUser()->getUsername();

    for(unsigned int i = 0; i < temp_list.size(); i++){
        if(user.compare(temp_list.at(i)) == 0){
            isRegistered = true;
        }
    }

    if(!isRegistered){
        temp_list.push_back(user);
        selected->setStudents(temp_list);
        control->getStorageAccess().saveProjects();

        std::string Message = "User: " + user + " is now registered in Project " + selected->getProjectName();

        QMessageBox::information(this, "Register Complete", Message.c_str() ,
                                        QMessageBox::Ok);

        itemSelected->setBackgroundColor(QColor(204, 51, 102));
    }
    else{
        std::string Message = "User: " + user + " is already registered in Project " + selected->getProjectName();

        QMessageBox::information(this, "Register Failed", Message.c_str() ,
                                        QMessageBox::Ok);
    }
}

void studentViewProject::on_pushButton_clicked()
{
    vector<string> temp_list = selected->getStudents();
    bool isRegistered = false;
    int pos = 0;
    string user = control->getLoggedUser()->getUsername();

    for(unsigned int i = 0; i < temp_list.size(); i++){
        if(user.compare(temp_list.at(i)) == 0){
            isRegistered = true;
            pos = i;
        }
    }

    if(isRegistered){
        temp_list.erase(temp_list.begin()+pos);

        selected->setStudents(temp_list);
        control->getStorageAccess().saveProjects();

        std::string Message = "User: " + user + " has left Project " + selected->getProjectName();

        QMessageBox::information(this, "Removal Complete", Message.c_str() ,
                                        QMessageBox::Ok);

        itemSelected->setBackgroundColor(QColor(0, 204, 51));
    }
    else{
        std::string Message = "User: " + user + " is not registered in Project " + selected->getProjectName();

        QMessageBox::information(this, "Removal Failed", Message.c_str() ,
                                        QMessageBox::Ok);
    }
}

void studentViewProject::reject()
{
    this->deleteLater();
    control->shutdown();
}

void studentViewProject::on_studentViewProject_destroyed()
{
    this->deleteLater();
}

void studentViewProject::on_ProjectList_itemClicked(QListWidgetItem *item)
{
    selected = control->getProject(-1, item->text().toStdString());
    control->setSelectedProject(selected);
    itemSelected = item;
}

void studentViewProject::buildProjectList()
{
    vector<Qualification*> qList = control->getQualList();
    vector<tuple<int, int>> perList = control->getLoggedUser()->getPersonalQual();

    for(int i = 0; i < control->getListSize(); i++){ //for each project

        Project* tm = control->getProject(i);

        vector<pair<int, int>> pqList = tm->getQualifications();
        vector<int> QualId_grade;
        vector<int> perId_grade;

        for(unsigned int j = 0; j < qList.size(); j++){
            if(qList.at(j)->getType() == 3){
                QualId_grade.push_back(j);
            }
        }

        for(unsigned int j = 0; j < pqList.size(); j++){
            for(unsigned int k = 0; k < QualId_grade.size(); k++){
                if(pqList.at(j).first == QualId_grade.at(k)){
                    perId_grade.push_back(j);
                }
            }
        }

        bool passed = true;

        for(unsigned int j = 0; j < perId_grade.size(); j++){
            int toPass = pqList.at(perId_grade.at(j)).second;
            int currGrade = get<1>(perList.at(QualId_grade.at(j)));

            if(currGrade < toPass){
                passed = false;
            }
        }

        if(passed){
            vector<string> temp_list = tm->getStudents();
            bool isRegistered = false;
            string user = control->getLoggedUser()->getUsername();

            for(unsigned int z = 0; z < temp_list.size(); z++){
                if(user.compare(temp_list.at(z)) == 0){
                    isRegistered = true;
                }
            }

            QListWidgetItem* t = new QListWidgetItem(tm->getProjectName().c_str());

            if(!isRegistered){
                t->setBackgroundColor(QColor(0, 204, 51));
            }
            else{
                t->setBackgroundColor(QColor(204, 51, 102));
            }

            ui->ProjectList->addItem(t);
        }
        ui->ProjectList->setSpacing(2);
        tm = 0;
    }
}


