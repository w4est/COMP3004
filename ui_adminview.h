/********************************************************************************
** Form generated from reading UI file 'adminview.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINVIEW_H
#define UI_ADMINVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AdminView
{
public:
    QListWidget *StudentList;
    QListWidget *ProjectList;
    QPushButton *EditProject;
    QLabel *StudentLabel;
    QLabel *ProjectLabel;
    QPushButton *RunPPID;
    QPushButton *CreateProject;
    QPushButton *LogoutButton;

    void setupUi(QDialog *AdminView)
    {
        if (AdminView->objectName().isEmpty())
            AdminView->setObjectName(QStringLiteral("AdminView"));
        AdminView->resize(480, 420);
        AdminView->setMinimumSize(QSize(480, 420));
        StudentList = new QListWidget(AdminView);
        StudentList->setObjectName(QStringLiteral("StudentList"));
        StudentList->setGeometry(QRect(258, 53, 201, 291));
        ProjectList = new QListWidget(AdminView);
        ProjectList->setObjectName(QStringLiteral("ProjectList"));
        ProjectList->setGeometry(QRect(18, 53, 231, 291));
        EditProject = new QPushButton(AdminView);
        EditProject->setObjectName(QStringLiteral("EditProject"));
        EditProject->setGeometry(QRect(238, 363, 99, 41));
        StudentLabel = new QLabel(AdminView);
        StudentLabel->setObjectName(QStringLiteral("StudentLabel"));
        StudentLabel->setGeometry(QRect(258, 3, 151, 41));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        StudentLabel->setFont(font);
        ProjectLabel = new QLabel(AdminView);
        ProjectLabel->setObjectName(QStringLiteral("ProjectLabel"));
        ProjectLabel->setGeometry(QRect(18, 3, 161, 41));
        ProjectLabel->setFont(font);
        RunPPID = new QPushButton(AdminView);
        RunPPID->setObjectName(QStringLiteral("RunPPID"));
        RunPPID->setGeometry(QRect(128, 363, 99, 41));
        CreateProject = new QPushButton(AdminView);
        CreateProject->setObjectName(QStringLiteral("CreateProject"));
        CreateProject->setGeometry(QRect(348, 363, 111, 41));
        LogoutButton = new QPushButton(AdminView);
        LogoutButton->setObjectName(QStringLiteral("LogoutButton"));
        LogoutButton->setGeometry(QRect(18, 373, 99, 27));

        retranslateUi(AdminView);

        QMetaObject::connectSlotsByName(AdminView);
    } // setupUi

    void retranslateUi(QDialog *AdminView)
    {
        AdminView->setWindowTitle(QApplication::translate("AdminView", "Dialog", 0));
        EditProject->setText(QApplication::translate("AdminView", "Edit Project", 0));
        StudentLabel->setText(QApplication::translate("AdminView", "Students:", 0));
        ProjectLabel->setText(QApplication::translate("AdminView", "Projects:", 0));
        RunPPID->setText(QApplication::translate("AdminView", "Run PPID", 0));
        CreateProject->setText(QApplication::translate("AdminView", "Create Project", 0));
        LogoutButton->setText(QApplication::translate("AdminView", "Logout", 0));
    } // retranslateUi

};

namespace Ui {
    class AdminView: public Ui_AdminView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINVIEW_H
