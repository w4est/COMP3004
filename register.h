#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include "LoginControl.h"

class LoginControl;

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(LoginControl *_control, QWidget *parent = 0, int _x = 150, int _y = 50, QString _username = "");
    ~Register();

private slots:
    void on_BackButton_clicked();

    void on_Register_destroyed();

    void on_ContinueButton_clicked();

    void on_CheckButton_clicked();

    void on_UsernameEdit_textEdited(const QString &arg1);

    void on_UsernameEdit_returnPressed();

    void reject();

private:
    Ui::Register *ui;
    QWidget *Window;

    LoginControl *control;

    bool preventReturn_back;
    bool firstLoad;
};

#endif // REGISTER_H
