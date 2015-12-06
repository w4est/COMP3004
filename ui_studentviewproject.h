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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_studentViewProject
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *ProjectLabel;
    QFrame *ProjectList_Frame;
    QHBoxLayout *horizontalLayout;
    QListWidget *ProjectList;
    QFrame *Flashy_Frame;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *ProjectName;
    QFrame *Register_Framess;
    QHBoxLayout *horizontalLayout_4;
    QLabel *RegisterValue;
    QFrame *Button_Frame;
    QGridLayout *gridLayout;
    QPushButton *BackButton;
    QPushButton *pushButton;
    QPushButton *JoinButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *studentViewProject)
    {
        if (studentViewProject->objectName().isEmpty())
            studentViewProject->setObjectName(QStringLiteral("studentViewProject"));
        studentViewProject->resize(557, 482);
        studentViewProject->setMinimumSize(QSize(550, 480));
        verticalLayout = new QVBoxLayout(studentViewProject);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        ProjectLabel = new QLabel(studentViewProject);
        ProjectLabel->setObjectName(QStringLiteral("ProjectLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ProjectLabel->sizePolicy().hasHeightForWidth());
        ProjectLabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        ProjectLabel->setFont(font);

        verticalLayout->addWidget(ProjectLabel);

        ProjectList_Frame = new QFrame(studentViewProject);
        ProjectList_Frame->setObjectName(QStringLiteral("ProjectList_Frame"));
        sizePolicy.setHeightForWidth(ProjectList_Frame->sizePolicy().hasHeightForWidth());
        ProjectList_Frame->setSizePolicy(sizePolicy);
        ProjectList_Frame->setFrameShape(QFrame::NoFrame);
        ProjectList_Frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(ProjectList_Frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ProjectList = new QListWidget(ProjectList_Frame);
        ProjectList->setObjectName(QStringLiteral("ProjectList"));
        sizePolicy.setHeightForWidth(ProjectList->sizePolicy().hasHeightForWidth());
        ProjectList->setSizePolicy(sizePolicy);
        ProjectList->setMinimumSize(QSize(517, 210));

        horizontalLayout->addWidget(ProjectList);


        verticalLayout->addWidget(ProjectList_Frame);

        Flashy_Frame = new QFrame(studentViewProject);
        Flashy_Frame->setObjectName(QStringLiteral("Flashy_Frame"));
        Flashy_Frame->setMinimumSize(QSize(520, 100));
        Flashy_Frame->setFrameShape(QFrame::NoFrame);
        Flashy_Frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(Flashy_Frame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        frame_4 = new QFrame(Flashy_Frame);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_4);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        ProjectName = new QLabel(frame_4);
        ProjectName->setObjectName(QStringLiteral("ProjectName"));
        ProjectName->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(ProjectName);


        horizontalLayout_2->addWidget(frame_4);

        Register_Framess = new QFrame(Flashy_Frame);
        Register_Framess->setObjectName(QStringLiteral("Register_Framess"));
        Register_Framess->setFrameShape(QFrame::StyledPanel);
        Register_Framess->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(Register_Framess);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        RegisterValue = new QLabel(Register_Framess);
        RegisterValue->setObjectName(QStringLiteral("RegisterValue"));
        RegisterValue->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(RegisterValue);


        horizontalLayout_2->addWidget(Register_Framess);


        verticalLayout->addWidget(Flashy_Frame);

        Button_Frame = new QFrame(studentViewProject);
        Button_Frame->setObjectName(QStringLiteral("Button_Frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Button_Frame->sizePolicy().hasHeightForWidth());
        Button_Frame->setSizePolicy(sizePolicy1);
        Button_Frame->setMinimumSize(QSize(0, 40));
        Button_Frame->setFrameShape(QFrame::NoFrame);
        Button_Frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(Button_Frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        BackButton = new QPushButton(Button_Frame);
        BackButton->setObjectName(QStringLiteral("BackButton"));
        BackButton->setMaximumSize(QSize(100, 40));

        gridLayout->addWidget(BackButton, 0, 0, 1, 1);

        pushButton = new QPushButton(Button_Frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(85, 20));
        pushButton->setMaximumSize(QSize(100, 40));

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        JoinButton = new QPushButton(Button_Frame);
        JoinButton->setObjectName(QStringLiteral("JoinButton"));
        JoinButton->setMinimumSize(QSize(85, 20));
        JoinButton->setMaximumSize(QSize(100, 40));

        gridLayout->addWidget(JoinButton, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);


        verticalLayout->addWidget(Button_Frame);


        retranslateUi(studentViewProject);

        QMetaObject::connectSlotsByName(studentViewProject);
    } // setupUi

    void retranslateUi(QDialog *studentViewProject)
    {
        studentViewProject->setWindowTitle(QApplication::translate("studentViewProject", "Dialog", 0));
        ProjectLabel->setText(QApplication::translate("studentViewProject", "Projects:", 0));
        ProjectName->setText(QApplication::translate("studentViewProject", "TextLabel", 0));
        RegisterValue->setText(QApplication::translate("studentViewProject", "TextLabel", 0));
        BackButton->setText(QApplication::translate("studentViewProject", "Back", 0));
        pushButton->setText(QApplication::translate("studentViewProject", "Leave", 0));
        JoinButton->setText(QApplication::translate("studentViewProject", "Join", 0));
    } // retranslateUi

};

namespace Ui {
    class studentViewProject: public Ui_studentViewProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTVIEWPROJECT_H
