#ifndef RUNPPID_H
#define RUNPPID_H

#include <QDialog>

namespace Ui {
class RunPPID;
}

class RunPPID : public QDialog
{
    Q_OBJECT

public:
    explicit RunPPID(QWidget *parent = 0);
    ~RunPPID();

private slots:
    void on_RunPPID_destroyed();

    void on_pushButton_clicked();

    void on_comboBox_activated(int index);

    void on_groupSize_valueChanged(int arg1);


    void on_BackButton_clicked();

private:
    Ui::RunPPID *ui;
};

#endif // RUNPPID_H
