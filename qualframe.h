#ifndef QUALFRAME_H
#define QUALFRAME_H

#include <QFrame>
#include <QWheelEvent>
#include <iostream>

namespace Ui {
class QualFrame;
}

class QualFrame : public QFrame
{
    Q_OBJECT

public:
    explicit QualFrame(QWidget *parent = 0);
    ~QualFrame();

    void setDescription(QString);
    void setId(QString);
    void setRange(int);
    void setType(int);
    int getSliderValue();
    void setValue(int);


protected:
    void wheelEvent(QWheelEvent*e);

private slots:
    void on_horizontalSlider_sliderPressed();

    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::QualFrame *ui;
    int type = -1;

};

#endif // QUALFRAME_H
