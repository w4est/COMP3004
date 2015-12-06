#include "editqualifications.h"
#include "ui_editqualifications.h"
#include "register.h"
#include <tuple>


EditQualifications::EditQualifications(LoginControl *_control, QWidget *parent, int _x, int _y, QString _username, int _page) :
    QDialog(parent),
    ui(new Ui::EditQualifications)
{
    Window = parent;
    control = _control;
    validUsername = _username;
    page = _page;

    this->move(_x, _y - 28);
    string title;

    if(page == 0){
        title = "Register Personal Qualifications";
    }
    else{
        title = "Register Desired Qualifications";
    }

    ui->setupUi(this);
    this->setWindowTitle(title.c_str());
    buildQualList();
}

EditQualifications::~EditQualifications()
{
    while(!frameList.empty())
    {
        QualFrame* temp = frameList.back();
        frameList.pop_back();
        temp->deleteLater();
    }
    layout->deleteLater();
    widget->deleteLater();
    scrollBoxLayout->deleteLater();
    delete ui;
}

void EditQualifications::on_EditQualifications_destroyed()
{
    this->deleteLater();
}

void EditQualifications::reject()
{
    if(page == 0){
        control->unregisterTempUser(validUsername.toStdString());
    }

    this->deleteLater();
    control->shutdown();
}

void EditQualifications::on_ContinueButton_clicked()
{
    vector<std::tuple<int, int>> newVec;
    QualFrame* temp;

    for(int i = 0; i < qualSize; i++){
        temp = (QualFrame*)layout->itemAt(i)->widget();
        newVec.push_back(make_tuple(i+1, temp->getSliderValue()));
    }
    if(page == 0){
        if(control->getCurrentUser()){
            control->getCurrentUser()->setPersonalQual(newVec);
        }
    }
    else if(page == 1){
        if(control->getCurrentUser()){
            control->getCurrentUser()->setDesiredQual(newVec);
        }
    }
    else{
    }
    //
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    if(page == 0){
        Window = control->getMParent()->GetForm(2,control,childPos.x(), childPos.y(), validUsername, 1);
                //new EditQualifications(control, Window, childPos.x(), childPos.y(), validUsername, 1);
        //Window->show();
        this->deleteLater();
    }
    else if(page == 1)
    {
        control->registerUser();
        Window = control->getMParent()->GetForm(0,control,childPos.x(), childPos.y());
                //new Login(control, Window, childPos.x(), childPos.y());
        //Window->show();
        this->deleteLater();
    }
}

void EditQualifications::on_BackButton_clicked()
{
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    if(page == 0){
        control->unregisterTempUser(validUsername.toStdString());
        Window = control->getMParent()->GetForm(1,control,childPos.x(), childPos.y(), validUsername,0);
                //new Register(control, Window, childPos.x(), childPos.y(), validUsername);
    }
    else{
        Window = control->getMParent()->GetForm(2,control,childPos.x(), childPos.y(), validUsername,0);
                //new EditQualifications(control, Window, childPos.x(), childPos.y(), validUsername, 0);
    }

    //Window->show();
    this->deleteLater();
}

//

void EditQualifications::buildQualList()
{
    if(page == 1){
        ui->page_title->setText("Desired Qualification Submission:");
        ui->ContinueButton->setText("Register");
    }

    vector<Qualification*> qualList;
    qualList = control->getQualList();

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
            form = buildQualWidget(QString(std::to_string(temp->getId()).c_str()), QString(temp->getPersonalDescription().c_str()), temp->getRange(), temp->getType());
        }
        else if(page == 1){
            form = buildQualWidget(QString(std::to_string(temp->getId()).c_str()), QString(temp->getDesiredDescription().c_str()), temp->getRange(), temp->getType());
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

QWidget* EditQualifications::buildQualWidget(QString _id, QString _desc, int _range, int type)
{
    QualFrame* frame = new QualFrame(Window);
    frameList.push_back(frame);
    frame->setDescription(_desc);
    int a = std::atoi(_id.toStdString().c_str());
    frame->setId(std::to_string( a + 1).c_str());
    frame->setRange(_range);
    frame->setType(type);

    return frame;
}

void EditQualifications::on_EditQualifications_rejected()
{
    this->reject();
}
