#ifndef LOGGEDIN_H
#define LOGGEDIN_H

#include <QDialog>

namespace Ui {
class LoggedIn;
}

class LoggedIn : public QDialog
{
    Q_OBJECT

public:
    explicit LoggedIn(QWidget *parent = 0);
    ~LoggedIn();

private slots:
    void on_LoggedIn_destroyed();

private:
    Ui::LoggedIn *ui;
};

#endif // LOGGEDIN_H
