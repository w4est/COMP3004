#ifndef EDITPROJECT_H
#define EDITPROJECT_H

#include <QDialog>
#include <QListWidgetItem>
#include <QScrollBar>
#include <QVBoxLayout>
#include "AdminControl.h"
#include "adminview.h"
#include "projectframe.h"
#include "qualification.h"

class projectFrame;

namespace Ui {
class EditProject;
}

class EditProject : public QDialog
{
    Q_OBJECT

public:
    explicit EditProject(AdminControl *, QWidget *parent = 0, int _x = 150, int _y = 50);
    ~EditProject();

    void setNewDescription();
protected:
    void mouseReleaseEvent(QMouseEvent *);

private slots:
    void on_EditProject_destroyed();

    void on_BackButton_clicked();

    void on_SaveButton_clicked();

    void reject();

private:
    Ui::EditProject *ui;
    QWidget *Window;
    AdminControl *control;

    void buildPage();

    QVBoxLayout *layout, *scrollBoxLayout;
    QWidget *widget;
    vector<projectFrame*> frameList;
};

#endif // EDITPROJECT_H
