#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QMessageBox>
#include "login_control.h"
#include "admincontrol.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0, int _x = 150, int _y = 50);
    ~Login();

private slots:
    void on_LoginButton_clicked();

    void on_RegisterButton_clicked();

    void on_Login_destroyed();

private:
    Ui::Login *ui;
    QWidget *Window;

    Login_Control *control;

};

#endif // LOGIN_H
