#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_LoginButton_clicked();

    void on_RegisterButton_clicked();

    void on_Login_destroyed();

private:
    Ui::Login *ui;
    QWidget *Window;
};

#endif // LOGIN_H
