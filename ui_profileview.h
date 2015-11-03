/********************************************************************************
** Form generated from reading UI file 'profileview.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEVIEW_H
#define UI_PROFILEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfileView
{
public:
    QPushButton *BackButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *SaveButton;
    QGroupBox *groupBox;
    QRadioButton *PersonalButton;
    QRadioButton *DesiredButton;

    void setupUi(QDialog *ProfileView)
    {
        if (ProfileView->objectName().isEmpty())
            ProfileView->setObjectName(QStringLiteral("ProfileView"));
        ProfileView->resize(979, 644);
        BackButton = new QPushButton(ProfileView);
        BackButton->setObjectName(QStringLiteral("BackButton"));
        BackButton->setGeometry(QRect(10, 610, 99, 27));
        scrollArea = new QScrollArea(ProfileView);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(20, 70, 931, 520));
        scrollArea->setMinimumSize(QSize(0, 520));
        scrollArea->setFrameShape(QFrame::Box);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 929, 518));
        scrollArea->setWidget(scrollAreaWidgetContents);
        SaveButton = new QPushButton(ProfileView);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));
        SaveButton->setGeometry(QRect(870, 610, 99, 27));
        groupBox = new QGroupBox(ProfileView);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(210, 0, 551, 80));
        PersonalButton = new QRadioButton(groupBox);
        PersonalButton->setObjectName(QStringLiteral("PersonalButton"));
        PersonalButton->setGeometry(QRect(70, 30, 101, 22));
        PersonalButton->setCheckable(true);
        PersonalButton->setChecked(true);
        DesiredButton = new QRadioButton(groupBox);
        DesiredButton->setObjectName(QStringLiteral("DesiredButton"));
        DesiredButton->setGeometry(QRect(230, 30, 161, 22));
        groupBox->raise();
        BackButton->raise();
        scrollArea->raise();
        SaveButton->raise();

        retranslateUi(ProfileView);

        QMetaObject::connectSlotsByName(ProfileView);
    } // setupUi

    void retranslateUi(QDialog *ProfileView)
    {
        ProfileView->setWindowTitle(QApplication::translate("ProfileView", "Dialog", 0));
        BackButton->setText(QApplication::translate("ProfileView", "Back", 0));
        SaveButton->setText(QApplication::translate("ProfileView", "Save", 0));
        groupBox->setTitle(QApplication::translate("ProfileView", "Qualifications", 0));
        PersonalButton->setText(QApplication::translate("ProfileView", "Personal", 0));
        DesiredButton->setText(QApplication::translate("ProfileView", "Desired in Partners", 0));
    } // retranslateUi

};

namespace Ui {
    class ProfileView: public Ui_ProfileView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEVIEW_H
