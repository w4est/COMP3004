#ifndef QUALIFICATION_FORM_H
#define QUALIFICATION_FORM_H

#include <QWidget>

namespace Ui {
class Qualification_Form;
}

class Qualification_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Qualification_Form(QWidget *parent = 0);
    ~Qualification_Form();

private:
    Ui::Qualification_Form *ui;
};

#endif // QUALIFICATION_FORM_H
