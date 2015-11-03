#include "qualframe.h"
#include "ui_qualframe.h"

QualFrame::QualFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::QualFrame)
{
    ui->setupUi(this);
}

QualFrame::~QualFrame()
{
    delete ui;
}

void QualFrame::setDescription(QString _desc)
{
    ui->QualDescription->setText(_desc);
}

void QualFrame::setId(QString _id)
{
    ui->qual_id->setText(_id + " :");
}

void QualFrame::setRange(int _range)
{
    ui->horizontalSlider->setRange(-_range, _range);
}

void QualFrame::setType(int _type)
{
    type = _type;

    if(type == 3){
        ui->Center_Label->setText("C+");
        ui->horizontalSlider->setRange(-7, 6);
    }
}

void QualFrame::wheelEvent(QWheelEvent *e)
{
    if(e){}
    ui->horizontalSlider->setValue(ui->horizontalSlider->value());
}

void QualFrame::on_horizontalSlider_sliderPressed()
{

}

void QualFrame::on_horizontalSlider_sliderMoved(int position)
{
    if(type == 2){ // true_false

    }
    else if(type == 3){ // grade
        QString grade = "";

        switch(position){
        case -7:
            grade = "Not Done";
            break;
        case -6:
            grade = "F";
            break;
        case -5:
            grade = "D-";
            break;
        case -4:
            grade = "D";
            break;
        case -3:
            grade = "D+";
            break;
        case -2:
            grade = "C-";
            break;
        case -1:
            grade = "C";
            break;
        case 0:
            grade = "C+";
            break;
        case 1:
            grade = "B-";
            break;
        case 2:
            grade = "B";
            break;
        case 3:
            grade = "B+";
            break;
        case 4:
            grade = "A-";
            break;
        case 5:
            grade = "A";
            break;
        case 6:
            grade = "A+";
            break;
        default:
            grade = "F";
            break;
        }

        ui->Center_Label->setText(grade);
    }
    else{
        ui->Center_Label->setText(std::to_string(position).c_str());
    }
}

int QualFrame::getSliderValue()
{
    return ui->horizontalSlider->value();
}

void QualFrame::on_horizontalSlider_valueChanged(int value)
{
    if(type == 2){ // true_false

    }
    else if(type == 3){ // grade
        QString grade = "";

        switch(value){
        case -7:
            grade = "Not Done";
            break;
        case -6:
            grade = "F";
            break;
        case -5:
            grade = "D-";
            break;
        case -4:
            grade = "D";
            break;
        case -3:
            grade = "D+";
            break;
        case -2:
            grade = "C-";
            break;
        case -1:
            grade = "C";
            break;
        case 0:
            grade = "C+";
            break;
        case 1:
            grade = "B-";
            break;
        case 2:
            grade = "B";
            break;
        case 3:
            grade = "B+";
            break;
        case 4:
            grade = "A-";
            break;
        case 5:
            grade = "A";
            break;
        case 6:
            grade = "A+";
            break;
        default:
            grade = "F";
            break;
        }

        ui->Center_Label->setText(grade);
    }
    else{
        ui->Center_Label->setText(std::to_string(value).c_str());
    }
}
