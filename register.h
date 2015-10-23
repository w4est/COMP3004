#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QDesktopWidget>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0, int _x = 150, int _y = 50);
    ~Register();

private slots:
    void on_BackButton_clicked();

    void on_Register_destroyed();

private:
    Ui::Register *ui;
    QWidget *Window;
};

#endif // REGISTER_H
