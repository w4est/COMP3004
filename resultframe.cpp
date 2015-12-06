#include "resultframe.h"
#include "ui_resultframe.h"
#include <iostream>

ResultFrame::ResultFrame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResultFrame)
{
    ui->setupUi(this);
}

ResultFrame::~ResultFrame()
{
    delete ui;
}

void ResultFrame::addStudent(QString _name)
{
    ui->StudentList->addItem(_name);
}
