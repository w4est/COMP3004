/********************************************************************************
** Form generated from reading UI file 'editproject.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPROJECT_H
#define UI_EDITPROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditProject
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *BackButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *SaveButton;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *qualDesc;
    QGroupBox *groupBox;
    QTextEdit *projectDescEdit;

    void setupUi(QDialog *EditProject)
    {
        if (EditProject->objectName().isEmpty())
            EditProject->setObjectName(QStringLiteral("EditProject"));
        EditProject->resize(769, 600);
        gridLayout = new QGridLayout(EditProject);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame = new QFrame(EditProject);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        BackButton = new QPushButton(frame);
        BackButton->setObjectName(QStringLiteral("BackButton"));

        horizontalLayout->addWidget(BackButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        SaveButton = new QPushButton(frame);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));

        horizontalLayout->addWidget(SaveButton);


        gridLayout->addWidget(frame, 1, 0, 1, 1);

        frame_2 = new QFrame(EditProject);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        scrollArea = new QScrollArea(frame_2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 475, 325));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 1, 0, 1, 1);

        qualDesc = new QLabel(frame_2);
        qualDesc->setObjectName(QStringLiteral("qualDesc"));
        qualDesc->setMinimumSize(QSize(250, 0));
        qualDesc->setFrameShape(QFrame::Box);
        qualDesc->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_2->addWidget(qualDesc, 1, 1, 1, 1);

        groupBox = new QGroupBox(frame_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 180));
        projectDescEdit = new QTextEdit(groupBox);
        projectDescEdit->setObjectName(QStringLiteral("projectDescEdit"));
        projectDescEdit->setGeometry(QRect(-5, 31, 741, 141));

        gridLayout_2->addWidget(groupBox, 0, 0, 1, 2);

        gridLayout_2->setColumnStretch(0, 99);

        gridLayout->addWidget(frame_2, 0, 0, 1, 1);


        retranslateUi(EditProject);

        QMetaObject::connectSlotsByName(EditProject);
    } // setupUi

    void retranslateUi(QDialog *EditProject)
    {
        EditProject->setWindowTitle(QApplication::translate("EditProject", "Dialog", 0));
        BackButton->setText(QApplication::translate("EditProject", "Back", 0));
        SaveButton->setText(QApplication::translate("EditProject", "Save", 0));
        qualDesc->setText(QString());
        groupBox->setTitle(QApplication::translate("EditProject", "Description:", 0));
    } // retranslateUi

};

namespace Ui {
    class EditProject: public Ui_EditProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPROJECT_H
