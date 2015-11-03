#ifndef STUPROJECTFRAME_H
#define STUPROJECTFRAME_H

#include <QFrame>
#include "StudentControl.h"

namespace Ui {
class stuProjectFrame;
}

class stuProjectFrame : public QFrame
{
    Q_OBJECT

public:
    explicit stuProjectFrame(StudentControl* _control, QWidget *parent = 0);
    ~stuProjectFrame();

    void setDescription(QString);
    void setChecked();
    bool isChecked();
    void setId(int);
    int getId();

protected:
    void mousePressEvent(QMouseEvent *);

private:
    Ui::stuProjectFrame *ui;
    StudentControl* control;
    int id;
};

#endif // STUPROJECTFRAME_H
