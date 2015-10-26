#ifndef VIEWPROFILE_H
#define VIEWPROFILE_H

#include <QDialog>

namespace Ui {
class ViewProfile;
}

class ViewProfile : public QDialog
{
    Q_OBJECT

public:
    explicit ViewProfile(QWidget *parent = 0);
    ~ViewProfile();

private:
    Ui::ViewProfile *ui;
};

#endif // VIEWPROFILE_H
