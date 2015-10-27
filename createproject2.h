#ifndef CREATEPROJECT2_H
#define CREATEPROJECT2_H

#include <QDialog>
#include "createproject.h"

namespace Ui {
class CreateProject2;
}

class CreateProject2 : public QDialog
{
    Q_OBJECT

public:
    explicit CreateProject2(QWidget *parent = 0, int _x = 150, int _y = 50, QString _username = "");
    CreateProject2(QWidget*,int, int, QString, QString, QString);
    ~CreateProject2();

private slots:
    void on_BackButton_clicked();
    void on_CreateProject2_destroyed();

private:
    Ui::CreateProject2 *ui;
    std::string projectDescription;
    std::string projectName;
    std::string username;
    QWidget *Window;
};

#endif // CREATEPROJECT2_H


