/********************************************************************************
** Form generated from reading UI file 'studentviewproject.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTVIEWPROJECT_H
#define UI_STUDENTVIEWPROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_studentViewProject
{
public:
    QGridLayout *gridLayout;
    QListWidget *ProjectList;
    QPushButton *JoinButton;
    QPushButton *BackButton;
    QLabel *ProjectLabel;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;

    void setupUi(QDialog *studentViewProject)
    {
        if (studentViewProject->objectName().isEmpty())
            studentViewProject->setObjectName(QStringLiteral("studentViewProject"));
        studentViewProject->resize(480, 420);
        studentViewProject->setMinimumSize(QSize(480, 420));
        gridLayout = new QGridLayout(studentViewProject);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        ProjectList = new QListWidget(studentViewProject);
        ProjectList->setObjectName(QStringLiteral("ProjectList"));

        gridLayout->addWidget(ProjectList, 1, 0, 1, 5);

        JoinButton = new QPushButton(studentViewProject);
        JoinButton->setObjectName(QStringLiteral("JoinButton"));
        JoinButton->setMinimumSize(QSize(85, 0));
        JoinButton->setMaximumSize(QSize(100, 40));

        gridLayout->addWidget(JoinButton, 2, 4, 1, 1);

        BackButton = new QPushButton(studentViewProject);
        BackButton->setObjectName(QStringLiteral("BackButton"));
        BackButton->setMaximumSize(QSize(100, 40));

        gridLayout->addWidget(BackButton, 2, 0, 1, 1);

        ProjectLabel = new QLabel(studentViewProject);
        ProjectLabel->setObjectName(QStringLiteral("ProjectLabel"));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        ProjectLabel->setFont(font);

        gridLayout->addWidget(ProjectLabel, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 1, 1, 1);

        pushButton = new QPushButton(studentViewProject);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(85, 20));
        pushButton->setMaximumSize(QSize(85, 40));

        gridLayout->addWidget(pushButton, 2, 3, 1, 1);


        retranslateUi(studentViewProject);

        QMetaObject::connectSlotsByName(studentViewProject);
    } // setupUi

    void retranslateUi(QDialog *studentViewProject)
    {
        studentViewProject->setWindowTitle(QApplication::translate("studentViewProject", "Dialog", 0));
        JoinButton->setText(QApplication::translate("studentViewProject", "Join", 0));
        BackButton->setText(QApplication::translate("studentViewProject", "Back", 0));
        ProjectLabel->setText(QApplication::translate("studentViewProject", "Projects:", 0));
        pushButton->setText(QApplication::translate("studentViewProject", "Leave", 0));
    } // retranslateUi

};

namespace Ui {
    class studentViewProject: public Ui_studentViewProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTVIEWPROJECT_H
