/********************************************************************************
** Form generated from reading UI file 'createproject2.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPROJECT2_H
#define UI_CREATEPROJECT2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateProject2
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label;
    QLabel *DescriptionLabel;
    QPushButton *CreateButton;
    QPushButton *BackButton;

    void setupUi(QDialog *CreateProject2)
    {
        if (CreateProject2->objectName().isEmpty())
            CreateProject2->setObjectName(QStringLiteral("CreateProject2"));
        CreateProject2->resize(576, 550);
        scrollArea = new QScrollArea(CreateProject2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 50, 241, 491));
        scrollArea->setFrameShape(QFrame::Box);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 239, 489));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label = new QLabel(CreateProject2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 231, 17));
        DescriptionLabel = new QLabel(CreateProject2);
        DescriptionLabel->setObjectName(QStringLiteral("DescriptionLabel"));
        DescriptionLabel->setGeometry(QRect(270, 50, 291, 421));
        QFont font;
        font.setKerning(true);
        DescriptionLabel->setFont(font);
        DescriptionLabel->setFrameShape(QFrame::Panel);
        DescriptionLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        DescriptionLabel->setWordWrap(true);
        CreateButton = new QPushButton(CreateProject2);
        CreateButton->setObjectName(QStringLiteral("CreateButton"));
        CreateButton->setGeometry(QRect(450, 510, 99, 27));
        BackButton = new QPushButton(CreateProject2);
        BackButton->setObjectName(QStringLiteral("BackButton"));
        BackButton->setGeometry(QRect(270, 510, 99, 27));

        retranslateUi(CreateProject2);

        QMetaObject::connectSlotsByName(CreateProject2);
    } // setupUi

    void retranslateUi(QDialog *CreateProject2)
    {
        CreateProject2->setWindowTitle(QApplication::translate("CreateProject2", "Dialog", 0));
        label->setText(QApplication::translate("CreateProject2", "Choose your Qualifications:", 0));
        DescriptionLabel->setText(QApplication::translate("CreateProject2", "Select Qualification Item to view description", 0));
        CreateButton->setText(QApplication::translate("CreateProject2", "Create", 0));
        BackButton->setText(QApplication::translate("CreateProject2", "Back", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateProject2: public Ui_CreateProject2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPROJECT2_H
