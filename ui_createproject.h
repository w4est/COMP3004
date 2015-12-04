/********************************************************************************
** Form generated from reading UI file 'createproject.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPROJECT_H
#define UI_CREATEPROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_CreateProject
{
public:
    QPushButton *BackButton;
    QPushButton *NextButton;
    QTextEdit *DescriptionEdit;
    QLineEdit *NameEdit;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *CreateProject)
    {
        if (CreateProject->objectName().isEmpty())
            CreateProject->setObjectName(QStringLiteral("CreateProject"));
        CreateProject->resize(406, 320);
        BackButton = new QPushButton(CreateProject);
        BackButton->setObjectName(QStringLiteral("BackButton"));
        BackButton->setGeometry(QRect(10, 280, 99, 27));
        NextButton = new QPushButton(CreateProject);
        NextButton->setObjectName(QStringLiteral("NextButton"));
        NextButton->setGeometry(QRect(290, 280, 99, 27));
        DescriptionEdit = new QTextEdit(CreateProject);
        DescriptionEdit->setObjectName(QStringLiteral("DescriptionEdit"));
        DescriptionEdit->setGeometry(QRect(10, 130, 371, 131));
        NameEdit = new QLineEdit(CreateProject);
        NameEdit->setObjectName(QStringLiteral("NameEdit"));
        NameEdit->setGeometry(QRect(10, 40, 371, 27));
        label = new QLabel(CreateProject);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 111, 17));
        label_2 = new QLabel(CreateProject);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 100, 91, 17));

        retranslateUi(CreateProject);

        QMetaObject::connectSlotsByName(CreateProject);
    } // setupUi

    void retranslateUi(QDialog *CreateProject)
    {
        CreateProject->setWindowTitle(QApplication::translate("CreateProject", "Dialog", 0));
        BackButton->setText(QApplication::translate("CreateProject", "Back", 0));
        NextButton->setText(QApplication::translate("CreateProject", "Next", 0));
        label->setText(QApplication::translate("CreateProject", "Project Name:", 0));
        label_2->setText(QApplication::translate("CreateProject", "Description:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateProject: public Ui_CreateProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPROJECT_H
