/********************************************************************************
** Form generated from reading UI file 'runppid.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNPPID_H
#define UI_RUNPPID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_RunPPID
{
public:
    QLabel *ProjectName;
    QSpinBox *groupSize;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QPushButton *RunPPIDButton;
    QPushButton *BackButton;

    void setupUi(QDialog *RunPPID)
    {
        if (RunPPID->objectName().isEmpty())
            RunPPID->setObjectName(QStringLiteral("RunPPID"));
        RunPPID->resize(274, 239);
        ProjectName = new QLabel(RunPPID);
        ProjectName->setObjectName(QStringLiteral("ProjectName"));
        ProjectName->setGeometry(QRect(100, 20, 67, 17));
        groupSize = new QSpinBox(RunPPID);
        groupSize->setObjectName(QStringLiteral("groupSize"));
        groupSize->setGeometry(QRect(110, 70, 48, 27));
        groupSize->setMinimum(2);
        label = new QLabel(RunPPID);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 70, 81, 17));
        comboBox = new QComboBox(RunPPID);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(100, 110, 121, 27));
        label_2 = new QLabel(RunPPID);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 100, 71, 41));
        label_2->setWordWrap(true);
        RunPPIDButton = new QPushButton(RunPPID);
        RunPPIDButton->setObjectName(QStringLiteral("RunPPIDButton"));
        RunPPIDButton->setGeometry(QRect(160, 200, 99, 27));
        BackButton = new QPushButton(RunPPID);
        BackButton->setObjectName(QStringLiteral("BackButton"));
        BackButton->setGeometry(QRect(10, 200, 99, 27));

        retranslateUi(RunPPID);

        QMetaObject::connectSlotsByName(RunPPID);
    } // setupUi

    void retranslateUi(QDialog *RunPPID)
    {
        RunPPID->setWindowTitle(QApplication::translate("RunPPID", "Dialog", 0));
        ProjectName->setText(QApplication::translate("RunPPID", "TextLabel", 0));
        label->setText(QApplication::translate("RunPPID", "Group Size", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("RunPPID", "Students", 0)
         << QApplication::translate("RunPPID", "Project", 0)
        );
        label_2->setText(QApplication::translate("RunPPID", "Prioitize PPID for:", 0));
        RunPPIDButton->setText(QApplication::translate("RunPPID", "Run PPID", 0));
        BackButton->setText(QApplication::translate("RunPPID", "Back", 0));
    } // retranslateUi

};

namespace Ui {
    class RunPPID: public Ui_RunPPID {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNPPID_H
