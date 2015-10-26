#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

#include "LoginControl.h"

class LoginControl;

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(LoginControl *_control, QWidget *parent = 0, int _x = 150, int _y = 50);
    ~Login();

private slots:
    void on_LoginButton_clicked();

    void on_RegisterButton_clicked();

    void on_Login_destroyed();

    void reEnable();

private:
    Ui::Login *ui;
    QWidget *Window;

    LoginControl *control;
};

#endif // LOGIN_H
