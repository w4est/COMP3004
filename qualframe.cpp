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
    ui->Center_Label->setText(std::to_string(position).c_str());
}

int QualFrame::getSliderValue()
{
    return ui->horizontalSlider->value();
}

void QualFrame::on_horizontalSlider_valueChanged(int value)
{
    ui->Center_Label->setText(std::to_string(value).c_str());
}

void QualFrame::setValue(int x){
    ui->horizontalSlider->setValue(x);
}
