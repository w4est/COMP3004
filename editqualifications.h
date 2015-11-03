#ifndef EDITQUALIFICATIONS_H
#define EDITQUALIFICATIONS_H

#include <QDialog>
#include <QListWidgetItem>
#include <QScrollBar>
#include <QVBoxLayout>
#include "LoginControl.h"
#include "login.h"
#include "qualframe.h"

class LoginControl;

namespace Ui {
class EditQualifications;
}

class EditQualifications : public QDialog
{
    Q_OBJECT

public:
    explicit EditQualifications(LoginControl *_control, QWidget *parent = 0, int _x = 150, int _y = 50, QString _username = "", int _page = 0);
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
    LoginControl *control;

    int page; // WHETHER PERSONAL_QUAL OR DESIRED_QUAL

    //
    QVBoxLayout *layout, *scrollBoxLayout;
    QWidget *widget;
    vector<QualFrame*> frameList;

    QString validUsername;
    int qualSize;

    void buildQualList();
    QWidget* buildQualWidget(QString, QString, int, int);
};

#endif // EDITQUALIFICATIONS_H
