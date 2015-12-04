#ifndef STUDENTVIEWPROJECT_H
#define STUDENTVIEWPROJECT_H

#include <QDialog>
#include "StudentControl.h"

class StudentControl;

namespace Ui {
class studentViewProject;
}

class studentViewProject : public QDialog
{
    Q_OBJECT

public:
    explicit studentViewProject(StudentControl *control, QWidget *parent = 0, int _x = 150, int _y = 50);
    ~studentViewProject();



private slots:
    void on_BackButton_clicked();

    void on_JoinButton_clicked();

    void reject();

    void on_studentViewProject_destroyed();

    void on_ProjectList_itemClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

private:
    Ui::studentViewProject *ui;
    QWidget *Window;
    StudentControl *control;

    Project* selected = 0;

    QListWidgetItem* itemSelected = 0;

    void buildProjectList();
};

#endif // STUDENTVIEWPROJECT_H
