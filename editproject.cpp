#include "editproject.h"
#include "ui_editproject.h"

EditProject::EditProject(QWidget *parent, int _x, int _y, QString _username):
    QDialog(parent),
    ui(new Ui::EditProject)
{
    //Create the window
    Window = parent;
    this->move(_x,_y-28);
    ui->setupUi(this);
}

EditProject::~EditProject()
{
    delete ui;
}

void EditProject::on_EditProject_destroyed()
{
    delete(this);
}

void EditProject::on_BackButton_clicked()
{
    //make next window
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    Window = new adminControl(Window, childPos.x(), childPos.y());
    Window->show();
    delete(this);
}
