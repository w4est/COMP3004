#ifndef VIEWPROFILE_H
#define VIEWPROFILE_H

#include <QDialog>
#include "login.h"

namespace Ui {
class ViewProfile;
}

class ViewProfile : public QDialog
{
    Q_OBJECT

public:
    explicit ViewProfile(QWidget *parent = 0, int _x = 150, int _y = 50, QString _username = "");
    ~ViewProfile();

private slots:
    void on_ViewProfile_destroyed();

    void on_BackButton_clicked();

private:
    Ui::ViewProfile *ui;
    QWidget *Window;
};

#endif // VIEWPROFILE_H
