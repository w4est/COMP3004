#ifndef RUNPPID_H
#define RUNPPID_H

#include <QDialog>
#include <QWidget>
#include <vector>
#include "AdminControl.h"
#include "adminview.h"

#include "ProfileEntity.h"

#include <math.h>
#include <stdlib.h>
#include <vector>
#include "ProfileEntity.h"
#include "project.h"


class AdminControl;

namespace Ui {
class RunPPID;
}

class RunPPID : public QDialog
{
    Q_OBJECT

public:
    explicit RunPPID(AdminControl* _control, QWidget *parent = 0, int _x = 150, int _y = 50, QString _projectName = "");

    int* MinOfTwo(int **studentList, int numStudents);//returns the index of the most compatible pair
    int GetMinStudent(int** studentList, int *currentGroup, int studentsInGroup, int numStudents);//returns the most compatible student for the current group


    std::vector<std::vector<ProfileEntity>> RunAlgorithmStudents(std::vector<ProfileEntity>* students, int numStudents, int groupSize);//run the student algorithm

    std::vector<std::vector<ProfileEntity>> RunAlgorithmProjects(std::vector<ProfileEntity>* students, int numStudents, int groupSize);//run the student algorithm

    std::vector<std::vector<ProfileEntity>> RunAlgorithmGrades(std::vector<ProfileEntity>* students, int numStudents, int groupSize);//run the student algorithm
    ~RunPPID();

private slots:
    void on_RunPPID_destroyed();

    void on_comboBox_activated(int index);

    void on_groupSize_valueChanged(int arg1);


    void on_BackButton_clicked();
    void reject();

    void on_RunPPIDButton_clicked();

private:
    Ui::RunPPID *ui;
    QWidget *Window;
    AdminControl* control;

    int groupSize;

};

#endif // RUNPPID_H
