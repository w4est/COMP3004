#ifndef EDITQUALIFICATIONS_H
#define EDITQUALIFICATIONS_H

#include <QDialog>
#include "LoginControl.h"

class LoginControl;

namespace Ui {
class EditQualifications;
}

class EditQualifications : public QDialog
{
    Q_OBJECT

public:
    explicit EditQualifications(LoginControl *_control, QWidget *parent = 0, int _x = 150, int _y = 50, QString _username = "");
    ~EditQualifications();

private slots:
    void on_EditQualifications_destroyed();

    void on_ContinueButton_clicked();

    void on_BackButton_clicked();

    void reject();

private:
    Ui::EditQualifications *ui;
    QWidget *Window;
    LoginControl *control;

    QString validUsername;
};

#endif // EDITQUALIFICATIONS_H
