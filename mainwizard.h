#ifndef MAINWIZARD_H
#define MAINWIZARD_H

#include <QWizard>
#include <iostream>
#include "VS_Files/ProfileEntity.h"

namespace Ui {
class MainWizard;
}

class MainWizard : public QWizard
{
    Q_OBJECT

public:
    explicit MainWizard(QWidget *parent = 0);
    ~MainWizard();

private slots:
    void on_MainWizard_rejected();

    void on_MainWizard_currentIdChanged(int id);

signals:
    void on_MainWizard_kill();

private:
    Ui::MainWizard *ui;
    ProfileEntity* tempProfile;

    std::string username;
};

#endif // MAINWIZARD_H
