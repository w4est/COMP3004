#include "qualification_form.h"
#include "ui_qualification_form.h"

Qualification_Form::Qualification_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Qualification_Form)
{
    ui->setupUi(this);
}

Qualification_Form::~Qualification_Form()
{
    delete ui;
}
