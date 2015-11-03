/********************************************************************************
** Form generated from reading UI file 'studentview.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTVIEW_H
#define UI_STUDENTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_StudentView
{
public:
    QPushButton *ViewProjectButton;
    QPushButton *LogoutButton;
    QPushButton *ViewProfileButton;

    void setupUi(QDialog *StudentView)
    {
        if (StudentView->objectName().isEmpty())
            StudentView->setObjectName(QStringLiteral("StudentView"));
        StudentView->resize(400, 300);
        ViewProjectButton = new QPushButton(StudentView);
        ViewProjectButton->setObjectName(QStringLiteral("ViewProjectButton"));
        ViewProjectButton->setGeometry(QRect(10, 30, 181, 151));
        ViewProjectButton->setFocusPolicy(Qt::NoFocus);
        LogoutButton = new QPushButton(StudentView);
        LogoutButton->setObjectName(QStringLiteral("LogoutButton"));
        LogoutButton->setGeometry(QRect(10, 260, 99, 27));
        LogoutButton->setFocusPolicy(Qt::NoFocus);
        ViewProfileButton = new QPushButton(StudentView);
        ViewProfileButton->setObjectName(QStringLiteral("ViewProfileButton"));
        ViewProfileButton->setGeometry(QRect(210, 30, 181, 151));
        ViewProfileButton->setFocusPolicy(Qt::NoFocus);

        retranslateUi(StudentView);

        QMetaObject::connectSlotsByName(StudentView);
    } // setupUi

    void retranslateUi(QDialog *StudentView)
    {
        StudentView->setWindowTitle(QApplication::translate("StudentView", "Dialog", 0));
        ViewProjectButton->setText(QApplication::translate("StudentView", "View Project", 0));
        LogoutButton->setText(QApplication::translate("StudentView", "Logout", 0));
        ViewProfileButton->setText(QApplication::translate("StudentView", "View Profile", 0));
    } // retranslateUi

};

namespace Ui {
    class StudentView: public Ui_StudentView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTVIEW_H
