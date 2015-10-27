#include "editqualifications.h"
#include "ui_editqualifications.h"
#include "register.h"
#include "qualframe.h"


EditQualifications::EditQualifications(LoginControl *_control, QWidget *parent, int _x, int _y, QString _username) :
    QDialog(parent),
    ui(new Ui::EditQualifications)
{
    Window = parent;
    control = _control;
    validUsername = _username;

    this->move(_x, _y);

    ui->setupUi(this);
    buildQualList();
}

EditQualifications::~EditQualifications()
{
    while(!layout->isEmpty())
    {
        delete layout->takeAt(0);
    }
    delete widget;
    delete scrollBoxLayout;
    delete ui;
}

void EditQualifications::on_EditQualifications_destroyed()
{
    control->unregisterTempUser(validUsername.toStdString());
    delete(this);
}

void EditQualifications::reject()
{
    control->unregisterTempUser(validUsername.toStdString());
    QDialog::reject();
}

void EditQualifications::on_ContinueButton_clicked()
{

}

void EditQualifications::on_BackButton_clicked()
{
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    control->unregisterTempUser(validUsername.toStdString());
    Window = new Register(control, Window, childPos.x(), childPos.y(), validUsername);
    Window->show();
    delete(this);
}

//

void EditQualifications::buildQualList()
{
    vector<pair<string, tuple<int, int, int, int>>> qualList;
    control->getQualList(qualList);

   ui->scrollArea->verticalScrollBar()->setSingleStep(256);

   QWidget *form;
   widget = new QWidget();

   layout = new QVBoxLayout();

   pair<string, tuple<int, int, int, int>> temp;



    for(unsigned int i = 0; i < qualList.size(); i++)
    {
        temp = qualList[i];
        form = buildQualWidget(QString(std::to_string(get<0>(temp.second)).c_str()), QString(temp.first.c_str()), get<2>(temp.second));

        layout->addWidget(form);
    }

    widget->setLayout(layout);

    scrollBoxLayout = new QVBoxLayout();
    scrollBoxLayout->setSpacing(25);

    ui->scrollArea->setWidget(widget);
    ui->scrollArea->setLayout(scrollBoxLayout);
}

QWidget* EditQualifications::buildQualWidget(QString _id, QString _desc, int _range)
{
    QualFrame* frame = new QualFrame(Window);
    frame->setDescription(_desc);
    frame->setId(_id);

    return frame;
}
