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

void QualFrame::wheelEvent(QWheelEvent *e)
{
    ui->horizontalSlider->setValue(ui->horizontalSlider->value());
}

void QualFrame::on_horizontalSlider_sliderPressed()
{

}
