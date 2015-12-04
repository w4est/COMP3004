/********************************************************************************
** Form generated from reading UI file 'editqualifications.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITQUALIFICATIONS_H
#define UI_EDITQUALIFICATIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditQualifications
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *BackButton;
    QPushButton *ContinueButton;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *page_title;

    void setupUi(QDialog *EditQualifications)
    {
        if (EditQualifications->objectName().isEmpty())
            EditQualifications->setObjectName(QStringLiteral("EditQualifications"));
        EditQualifications->resize(870, 623);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EditQualifications->sizePolicy().hasHeightForWidth());
        EditQualifications->setSizePolicy(sizePolicy);
        EditQualifications->setMinimumSize(QSize(870, 623));
        EditQualifications->setMaximumSize(QSize(16777215, 623));
        gridLayout_2 = new QGridLayout(EditQualifications);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 2, 1, 1);

        BackButton = new QPushButton(EditQualifications);
        BackButton->setObjectName(QStringLiteral("BackButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(BackButton->sizePolicy().hasHeightForWidth());
        BackButton->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(BackButton, 1, 1, 1, 1);

        ContinueButton = new QPushButton(EditQualifications);
        ContinueButton->setObjectName(QStringLiteral("ContinueButton"));
        sizePolicy1.setHeightForWidth(ContinueButton->sizePolicy().hasHeightForWidth());
        ContinueButton->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(ContinueButton, 1, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(EditQualifications);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy2);
        scrollArea->setMinimumSize(QSize(0, 520));
        scrollArea->setFocusPolicy(Qt::WheelFocus);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 848, 518));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        page_title = new QLabel(EditQualifications);
        page_title->setObjectName(QStringLiteral("page_title"));
        page_title->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        page_title->setFont(font);
        page_title->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(page_title, 0, 0, 1, 1);

        gridLayout_2->setRowMinimumHeight(1, 350);

        retranslateUi(EditQualifications);

        QMetaObject::connectSlotsByName(EditQualifications);
    } // setupUi

    void retranslateUi(QDialog *EditQualifications)
    {
        EditQualifications->setWindowTitle(QApplication::translate("EditQualifications", "Dialog", 0));
        BackButton->setText(QApplication::translate("EditQualifications", "Back", 0));
        ContinueButton->setText(QApplication::translate("EditQualifications", "Continue", 0));
        page_title->setText(QApplication::translate("EditQualifications", "Personal Qualification Submission:", 0));
    } // retranslateUi

};

namespace Ui {
    class EditQualifications: public Ui_EditQualifications {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITQUALIFICATIONS_H
