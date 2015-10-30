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
protected:
    void mousePressEvent(QMouseEvent *);
private:
    Ui::projectFrame *ui;
    AdminControl* control;
};

#endif // PROJECTFRAME_H
