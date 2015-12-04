/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QGridLayout *gridLayout_3;
    QPushButton *BackButton;
    QFrame *Username_Container;
    QGridLayout *gridLayout_2;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *UsernameEdit;
    QPushButton *CheckButton;
    QLabel *Warning_Label;
    QFrame *frame;
    QPushButton *ContinueButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->setEnabled(true);
        Register->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Register->sizePolicy().hasHeightForWidth());
        Register->setSizePolicy(sizePolicy);
        Register->setMinimumSize(QSize(400, 300));
        gridLayout_3 = new QGridLayout(Register);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        BackButton = new QPushButton(Register);
        BackButton->setObjectName(QStringLiteral("BackButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(BackButton->sizePolicy().hasHeightForWidth());
        BackButton->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(BackButton, 3, 0, 1, 1);

        Username_Container = new QFrame(Register);
        Username_Container->setObjectName(QStringLiteral("Username_Container"));
        sizePolicy.setHeightForWidth(Username_Container->sizePolicy().hasHeightForWidth());
        Username_Container->setSizePolicy(sizePolicy);
        Username_Container->setLayoutDirection(Qt::LeftToRight);
        Username_Container->setAutoFillBackground(false);
        Username_Container->setFrameShape(QFrame::Box);
        Username_Container->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(Username_Container);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(3);
        gridLayout_2->setContentsMargins(-1, 3, -1, 4);
        frame_2 = new QFrame(Username_Container);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setEnabled(true);
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(6);
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        font.setKerning(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        label->setMargin(0);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame_2, 0, 0, 1, 1);

        UsernameEdit = new QLineEdit(Username_Container);
        UsernameEdit->setObjectName(QStringLiteral("UsernameEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(90);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(UsernameEdit->sizePolicy().hasHeightForWidth());
        UsernameEdit->setSizePolicy(sizePolicy2);
        UsernameEdit->setLayoutDirection(Qt::LeftToRight);
        UsernameEdit->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(UsernameEdit, 1, 0, 1, 1);

        CheckButton = new QPushButton(Username_Container);
        CheckButton->setObjectName(QStringLiteral("CheckButton"));
        sizePolicy1.setHeightForWidth(CheckButton->sizePolicy().hasHeightForWidth());
        CheckButton->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(9);
        CheckButton->setFont(font1);
        CheckButton->setLayoutDirection(Qt::RightToLeft);

        gridLayout_2->addWidget(CheckButton, 1, 1, 1, 1);

        Warning_Label = new QLabel(Username_Container);
        Warning_Label->setObjectName(QStringLiteral("Warning_Label"));
        Warning_Label->setEnabled(false);
        Warning_Label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(Warning_Label, 0, 1, 1, 1);


        gridLayout_3->addWidget(Username_Container, 0, 0, 1, 3);

        frame = new QFrame(Register);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout_3->addWidget(frame, 3, 1, 1, 1);

        ContinueButton = new QPushButton(Register);
        ContinueButton->setObjectName(QStringLiteral("ContinueButton"));
        ContinueButton->setEnabled(false);
        sizePolicy1.setHeightForWidth(ContinueButton->sizePolicy().hasHeightForWidth());
        ContinueButton->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(ContinueButton, 3, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 1, 0, 1, 1);


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Register Username", 0));
        BackButton->setText(QApplication::translate("Register", "Back", 0));
        label->setText(QApplication::translate("Register", "Choose Username :", 0));
        UsernameEdit->setText(QString());
        UsernameEdit->setPlaceholderText(QApplication::translate("Register", "Enter Desired Username", 0));
        CheckButton->setText(QApplication::translate("Register", "Check Availabilty", 0));
        Warning_Label->setText(QString());
        ContinueButton->setText(QApplication::translate("Register", "Continue", 0));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
