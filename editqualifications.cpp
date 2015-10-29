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

    ui->setupUi(this);
    buildQualList();
}

EditQualifications::~EditQualifications()
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

void EditQualifications::on_EditQualifications_destroyed()
{
    delete(this);
}

void EditQualifications::reject()
{
    if(page == 0){
        control->unregisterTempUser(validUsername.toStdString());
    }
    QDialog::reject();
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
        cout << "edit:: register :: " << control->getCurrentUser()<<endl;
        if(control->getCurrentUser()){
            control->getCurrentUser()->setPersonalQual(newVec);
        }
    }
    else if(page == 1){
        cout << "edit:: register :: " << control->getCurrentUser()<<endl;
        if(control->getCurrentUser()){
            control->getCurrentUser()->setDesiredQual(newVec);
        }
    }
    else{
    }
    //
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    if(page == 0){
        Window = new EditQualifications(control, Window, childPos.x(), childPos.y(), validUsername, 1);
        Window->show();
        delete(this);
    }
    else if(page == 1)
    {
        cout << control->getCurrentUser()->getPersonalQual().size() << " || " << control->getCurrentUser()->getDesiredQual().size() << " || " << control->getCurrentUser()->getUsername() << endl;
        control->registerUser();
        Window = new Login(control, Window, childPos.x(), childPos.y());
        Window->show();
        delete(this);
    }
}

void EditQualifications::on_BackButton_clicked()
{
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    if(page == 0){
        control->unregisterTempUser(validUsername.toStdString());
        Window = new Register(control, Window, childPos.x(), childPos.y(), validUsername);
    }
    else{
        Window = new EditQualifications(control, Window, childPos.x(), childPos.y(), validUsername, 0);
    }

    Window->show();
    delete(this);
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
            form = buildQualWidget(QString(std::to_string(temp->getId()).c_str()), QString(temp->getPersonalDescription().c_str()), temp->getRange());
        }
        else if(page == 1){
            form = buildQualWidget(QString(std::to_string(temp->getId()).c_str()), QString(temp->getDesiredDescription().c_str()), temp->getRange());
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

QWidget* EditQualifications::buildQualWidget(QString _id, QString _desc, int _range)
{
    QualFrame* frame = new QualFrame(Window);
    frameList.push_back(frame);
    frame->setDescription(_desc);
    frame->setId(_id);

    return frame;
}

void EditQualifications::on_EditQualifications_rejected()
{
    this->reject();
}
