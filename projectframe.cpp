#include "projectframe.h"
#include "ui_projectframe.h"
#include <iostream>

projectFrame::projectFrame(AdminControl* _control, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::projectFrame)
{
    control = _control;
    ui->setupUi(this);
}

projectFrame::~projectFrame()
{
    control = 0;
    delete ui;
}

void projectFrame::setDescription(QString _desc)
{
    ui->label->setText(_desc);
}

void projectFrame::setChecked()
{
    ui->checkBox->setChecked(true);
}

void projectFrame::mousePressEvent(QMouseEvent *_event)
{
    std::cout << "frame" << std::endl;
    this->setStyleSheet("projectFrame { background: rgb(204, 153, 51); selection-background-color: rgb(0, 0, 0)}");
    control->setCurrentFrame(this);
}
