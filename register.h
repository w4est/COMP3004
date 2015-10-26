#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include "login_control.h"

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0, int _x = 150, int _y = 50, QString _username = "");
    ~Register();

private slots:
    void on_BackButton_clicked();

    void on_Register_destroyed();

    void on_ContinueButton_clicked();

    void on_CheckButton_clicked();

    void on_UsernameEdit_textEdited(const QString &arg1);

private:
    Ui::Register *ui;
    QWidget *Window;

    Login_Control *control;
};

#endif // REGISTER_H
