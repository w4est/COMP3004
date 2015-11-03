#include "projectframe.h"
#include "ui_projectframe.h"
#include <iostream>

projectFrame::projectFrame(AdminControl* _control, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::projectFrame)
{
    control = _control;
    ui->setupUi(this);

    ui->Slider_value->setVisible(false);
    ui->horizontalSlider->setVisible(false);
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

void projectFrame::setGrade(int _grade)
{
    grade = _grade;
    ui->horizontalSlider->setValue(_grade);
    QString g = "";

    switch(_grade){
    case -7:
        g = "Open";
        break;
    case -6:
        g = "F";
        break;
    case -5:
        g = "D-";
        break;
    case -4:
        g = "D";
        break;
    case -3:
        g = "D+";
        break;
    case -2:
        g = "C-";
        break;
    case -1:
        g = "C";
        break;
    case 0:
        g = "C+";
        break;
    case 1:
        g = "B-";
        break;
    case 2:
        g = "B";
        break;
    case 3:
        g = "B+";
        break;
    case 4:
        g = "A-";
        break;
    case 5:
        g = "A";
        break;
    case 6:
        g = "A+";
        break;
    default:
        g = "F";
        break;
    }

    ui->Slider_value->setText(g);

    ui->Slider_value->setVisible(true);
    ui->horizontalSlider->setVisible(true);
}

void projectFrame::on_horizontalSlider_valueChanged(int value)
{
        QString g = "";

        switch(value){
        case -7:
            g = "Open";
            break;
        case -6:
            g = "F";
            break;
        case -5:
            g = "D-";
            break;
        case -4:
            g = "D";
            break;
        case -3:
            g = "D+";
            break;
        case -2:
            g = "C-";
            break;
        case -1:
            g = "C";
            break;
        case 0:
            g = "C+";
            break;
        case 1:
            g = "B-";
            break;
        case 2:
            g = "B";
            break;
        case 3:
            g = "B+";
            break;
        case 4:
            g = "A-";
            break;
        case 5:
            g = "A";
            break;
        case 6:
            g = "A+";
            break;
        default:
            g = "F";
            break;
        }

        ui->Slider_value->setText(g);
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

int projectFrame::getGrade()
{
    return ui->horizontalSlider->value();
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
