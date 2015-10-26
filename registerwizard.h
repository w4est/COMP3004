#ifndef REGISTERWIZARD_H
#define REGISTERWIZARD_H

#include <QWizardPage>

namespace Ui {
class RegisterWizard;
}

class RegisterWizard : public QWizardPage
{
    Q_OBJECT

public:
    explicit RegisterWizard(QWidget *parent = 0);
    ~RegisterWizard();

private:
    Ui::RegisterWizard *ui;
};

#endif // REGISTERWIZARD_H
