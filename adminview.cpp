#include "adminview.h"
#include "ui_adminview.h"

AdminView::AdminView(AdminControl *_control, QWidget *parent, int _x, int _y) :
    QDialog(parent),
    ui(new Ui::AdminView)
{
    Window = parent;
    control = _control;

    this->move(_x, _y - 28);

    ui->setupUi(this);
    std::cout << "ADMINView:: ctor" << std::endl;
}

AdminView::~AdminView()
{
    std::cout << "ADMINCONTROL:: dtor" << std::endl;
    control = 0;
    delete ui;
}

void AdminView::on_CreateProject_clicked()
{
    QPoint childPos = this->mapToGlobal(QPoint(0,0));
    //Window = new CreateProject(Window, childPos.x(), childPos.y(), username.c_str());
    //Window->show();
    //delete(projectHolder);
    //delete(this);
}

void AdminView::on_LogoutButton_clicked()
{
    control->logout(new QPoint(this->mapToGlobal(QPoint(0,0))));
    //delete(this);
}

void AdminView::on_RunPPID_clicked()
{

}

void AdminView::on_EditProject_clicked()
{

}

void AdminView::on_AdminView_destroyed()
{

}

/*USELESS*/
void AdminView::on_AdminView_rejected()
{
}

void AdminView::reject()
{
    delete(this);
}
