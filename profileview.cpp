#include "profileview.h"
#include "ui_profileview.h"

ProfileView::ProfileView(StudentControl *_control, QWidget *parent, int _x, int _y) :
    QDialog(parent),
    ui(new Ui::ProfileView)
{
    Window = parent;
    control = _control;

    this->move(_x, _y - 28);

    ui->setupUi(this);

}

ProfileView::~ProfileView()
{
    control = 0;
    delete ui;
}

//Go back! Pass container to new window, and delete self.
void ProfileView::on_BackButton_clicked()
{
    //QPoint childPos = this->mapToGlobal(QPoint(0,0));
    control->logout(new QPoint(this->mapToGlobal(QPoint(0,0))));
}

void ProfileView::reject()
{
    delete(this);
}
