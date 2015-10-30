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

/*
 * change description
 */
void projectFrame::setDescription(QString _desc)
{
    ui->label->setText(_desc);
}

/*
 * changes checkbox to true
 */
void projectFrame::setChecked()
{
    ui->checkBox->setChecked(true);
}

bool projectFrame::isChecked()
{
    return ui->checkBox->isChecked();
}

void projectFrame::setId(int _id){
    id = _id;
}

int projectFrame::getId()
{
    return id;
}

/*
 * when mouse on current frame, change self color and set AdminControl's current frame placeholder to this
 */
void projectFrame::mousePressEvent(QMouseEvent *_event)
{
    if(_event){};
    this->setStyleSheet("projectFrame { background: rgb(204, 153, 51); selection-background-color: rgb(0, 0, 0)}");
    control->setCurrentFrame(this);
}
