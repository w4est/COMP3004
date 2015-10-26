#include "registerwizard.h"
#include "ui_registerwizard.h"

RegisterWizard::RegisterWizard(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::RegisterWizard)
{
    ui->setupUi(this);
}

RegisterWizard::~RegisterWizard()
{
    delete ui;
}
