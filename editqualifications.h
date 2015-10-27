#ifndef EDITQUALIFICATIONS_H
#define EDITQUALIFICATIONS_H

#include <QDialog>
#include "login_control.h"

namespace Ui {
class EditQualifications;
}

class EditQualifications : public QDialog
{
    Q_OBJECT

public:
    explicit EditQualifications(QWidget *parent = 0, int _x = 150, int _y = 50, QString _username = "");
    ~EditQualifications();

private slots:
    void on_EditQualifications_destroyed();

    void on_ContinueButton_clicked();

    void on_BackButton_clicked();

    void reject();

    void on_EditQualifications_rejected();

private:
    Ui::EditQualifications *ui;
    QWidget *Window;
    Login_Control *control;

    QString validUsername;
};

#endif // EDITQUALIFICATIONS_H
