#ifndef RESULTFRAME_H
#define RESULTFRAME_H

#include <QWidget>

namespace Ui {
class ResultFrame;
}

class ResultFrame : public QWidget
{
    Q_OBJECT

public:
    explicit ResultFrame(QWidget *parent = 0);
    ~ResultFrame();

    void addStudent(QString);

private:
    Ui::ResultFrame *ui;
};

#endif // RESULTFRAME_H
