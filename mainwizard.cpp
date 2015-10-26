#include "mainwizard.h"
#include "ui_mainwizard.h"

MainWizard::MainWizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::MainWizard)
{
    ui->setupUi(this);
}

MainWizard::~MainWizard()
{
    //delete tempProfile;
    delete ui;
}

void MainWizard::on_MainWizard_rejected()
{
    emit(on_MainWizard_kill());
}

void MainWizard::on_MainWizard_currentIdChanged(int id)
{
    if(id == 0){
        this->button(QWizard::NextButton)->setEnabled(false);
    }
    else if(id == 1 && !tempProfile){
        //tempProfile = new ProfileEntity(username);
    }
}
