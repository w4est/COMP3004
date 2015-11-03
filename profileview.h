#ifndef PROFILEVIEW_H
#define PROFILEVIEW_H

#include <QDialog>
#include <QListWidgetItem>
#include <QScrollBar>
#include <QVBoxLayout>
#include "StudentControl.h"
#include "qualframe.h"

class StudentControl;

namespace Ui {
class ProfileView;
}

class ProfileView : public QDialog
{
    Q_OBJECT

public:
    explicit ProfileView(StudentControl *_control, QWidget *parent = 0, int _x = 150, int _y = 50);
    ~ProfileView();

private slots:
    void on_BackButton_clicked();

    void reject();

    void on_ProfileView_destroyed();

    QWidget* buildQualWidget(QString _id, QString _desc, int _range);
    void buildQualList();

    void on_SaveButton_clicked();

private:
    Ui::ProfileView *ui;
    QWidget *Window;

    StudentControl *control;
    int page;
    int qualSize;
    vector<QualFrame*> frameList;
    QLayout* layout;
    QWidget* widget;
    QVBoxLayout* scrollBoxLayout;

};

#endif // PROFILEVIEW_H
