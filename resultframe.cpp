#include "resultframe.h"
#include "ui_resultframe.h"
#include <iostream>

ResultFrame::ResultFrame(QWidget *parent, int _team) :
    QWidget(parent),
    ui(new Ui::ResultFrame)
{
    ui->setupUi(this);
    QString name = std::to_string(_team).c_str();
    ui->TeamName->setText(name);
}

ResultFrame::~ResultFrame()
{
    delete ui;
}

void ResultFrame::addStudent(QString _name)
{
    ui->StudentList->addItem(_name);
}
