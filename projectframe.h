#ifndef PROJECTFRAME_H
#define PROJECTFRAME_H

#include <QFrame>
#include "AdminControl.h"

namespace Ui {
class projectFrame;
}

class projectFrame : public QFrame
{
    Q_OBJECT

public:
    explicit projectFrame(AdminControl* _control, QWidget *parent = 0);
    ~projectFrame();

    void setDescription(QString);
    void setChecked();
    void setGrade(int);
    bool isChecked();
    void setId(int);
    int getId();
    int getGrade();

protected:
    void mousePressEvent(QMouseEvent *);

private slots:
    void on_horizontalSlider_valueChanged(int value);
private:
    Ui::projectFrame *ui;
    AdminControl* control;
    int id;
    int grade = 1;
};

#endif // PROJECTFRAME_H
