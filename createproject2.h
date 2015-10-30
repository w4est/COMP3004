#ifndef CREATEPROJECT2_H
#define CREATEPROJECT2_H

#include <QDialog>
#include <QListWidgetItem>
#include <QScrollBar>
#include <QVBoxLayout>
#include "AdminControl.h"
#include "createproject.h"
#include "project.h"
#include "projectframe.h"
#include "qualification.h"

class AdminControl;

namespace Ui {
class CreateProject2;
}

class CreateProject2 : public QDialog
{
    Q_OBJECT

public:
    explicit CreateProject2(AdminControl* _control, QWidget *parent = 0, int _x = 150, int _y = 50, QString _username = "");
    CreateProject2(AdminControl* _comtrol, QWidget*,int, int, QString, QString, QString);
    ~CreateProject2();

    void setNewDescription();
protected:
    void mouseReleaseEvent(QMouseEvent *);

private slots:
    void on_BackButton_clicked();
    void on_CreateProject2_destroyed();

    void on_CreateButton_clicked();
    void reject();

private:
    Ui::CreateProject2 *ui;
    QWidget *Window;
    AdminControl *control;

    std::string projectDescription;
    std::string projectName;
    std::string username;

    void buildPage();

    QVBoxLayout *layout, *scrollBoxLayout;
    QWidget *widget;
    vector<projectFrame*> frameList;
};

#endif // CREATEPROJECT2_H


