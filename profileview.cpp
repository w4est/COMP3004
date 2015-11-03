#include "profileview.h"
#include "ui_profileview.h"

ProfileView::ProfileView(StudentControl *_control, QWidget *parent, int _x, int _y) :
    QDialog(parent),
    ui(new Ui::ProfileView)
{
    Window = parent;
    control = _control;
    page = 0;
    this->move(_x, _y - 28);

    ui->setupUi(this);

    string title = "View and Edit Profile";
    this->setWindowTitle(title.c_str());
    buildQualList();


}

ProfileView::~ProfileView()
{
    control = 0;
    delete ui;
}

/*
 * Pass window container, make StudentView again
 * Queue for deletion
 * */

void ProfileView::on_BackButton_clicked()
{

    control->StudentPage(Window,this->x(),this->y());
    this->deleteLater();

}

void ProfileView::reject()
{
    this->deleteLater();
    control->shutdown();
}

/*
 * Delete when forcefully closed
 *
 * */
void ProfileView::on_ProfileView_destroyed()
{
    this->deleteLater();
}


/*
 * Build Qualification List
 *
 * */

void ProfileView::buildQualList()
{


    vector<Qualification*> qualList;
    qualList = control->getQualList();
    Account = control->getLoggedUser();

    personalTupleList = Account->getPersonalQual();
    desiredTupleList = Account->getDesiredQual();

    qualSize = qualList.size();

   ui->scrollArea->verticalScrollBar()->setSingleStep(256);

   QWidget *form;
   widget = new QWidget();
   layout = new QVBoxLayout();

    Qualification* temp;

    for(unsigned int i = 0; i < qualList.size(); i++)
    {
        temp = qualList[i];

        if(page == 0){
            form = buildQualWidget(QString(std::to_string(temp->getId()).c_str()), QString(temp->getPersonalDescription().c_str()), temp->getRange(), get<1>(personalTupleList.at(i)),temp->getType());
        }
        else if(page == 1){
            form = buildQualWidget(QString(std::to_string(temp->getId()).c_str()), QString(temp->getDesiredDescription().c_str()), temp->getRange(), get<1>(desiredTupleList.at(i)),temp->getType());
        }
        layout->addWidget(form);
    }

    temp = 0;
    widget->setLayout(layout);

    scrollBoxLayout = new QVBoxLayout();
    scrollBoxLayout->setSpacing(25);

    ui->scrollArea->setWidget(widget);
    ui->scrollArea->setLayout(scrollBoxLayout);
}

/*
 * Create Qualification Frame
 *
 * */

QWidget* ProfileView::buildQualWidget(QString _id, QString _desc, int _range, int value, int type)
{
    QualFrame* frame = new QualFrame(Window);
    frameList.push_back(frame);
    frame->setDescription(_desc);
    int a = std::atoi(_id.toStdString().c_str());
    frame->setId(std::to_string( a + 1).c_str());
    frame->setRange(_range);
    frame->setValue(value);
    frame->setType(type);

    return frame;
}


/*
 * Save Profile
 *
 * */
void ProfileView::on_SaveButton_clicked()
{
    //Save current page.
    if (page == 0){
        for (int i = 0; i < qualSize; i++){
            get<1>(personalTupleList.at(i)) = frameList.at(i)->getSliderValue();

        }
    }
    else{
        for (int i = 0; i < qualSize; i++){
            get<1>(desiredTupleList.at(i)) = frameList.at(i)->getSliderValue();

        }
    }
    //Save to manager.
    Account->setPersonalQual(personalTupleList);
    Account->setDesiredQual(desiredTupleList);
    control->getStorageAccess().saveProfile();
}

/*
 * Change QualFrame Values to Desired Profile values
 *
 * */

void ProfileView::on_DesiredButton_clicked()
{
    page = 1;


    for (int i = 0; i < qualSize; i++){
        get<1>(personalTupleList.at(i)) = frameList.at(i)->getSliderValue();
        frameList.at(i)->setValue(get<1>(desiredTupleList.at(i)));
    }

}

/*
 * Change QualFrame Values to Personal Profile values
 *
 * */

void ProfileView::on_PersonalButton_clicked()
{
    page = 0;


    for (int i = 0; i < qualSize; i++){
        get<1>(desiredTupleList.at(i)) = frameList.at(i)->getSliderValue();
        frameList.at(i)->setValue(get<1>(personalTupleList.at(i)));
    }

}
