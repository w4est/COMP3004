/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFrame *frame_5;
    QGridLayout *gridLayout_2;
    QPushButton *RegisterButton;
    QFrame *frame_2;
    QFrame *frame_4;
    QFrame *frame_6;
    QGridLayout *gridLayout_3;
    QLabel *Warning_Label;
    QFrame *frame_3;
    QPushButton *LoginButton;
    QLineEdit *UsernameBox;
    QFrame *frame;
    QFrame *frame_7;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->setEnabled(true);
        Login->resize(400, 300);
        centralWidget = new QWidget(Login);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame_5 = new QFrame(centralWidget);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy);
        frame_5->setFrameShape(QFrame::NoFrame);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_5);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        RegisterButton = new QPushButton(frame_5);
        RegisterButton->setObjectName(QStringLiteral("RegisterButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(RegisterButton->sizePolicy().hasHeightForWidth());
        RegisterButton->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(RegisterButton, 0, 0, 1, 1, Qt::AlignLeft|Qt::AlignBottom);


        gridLayout->addWidget(frame_5, 5, 0, 1, 1);

        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame_2, 2, 3, 1, 1);

        frame_4 = new QFrame(centralWidget);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::NoFrame);
        frame_4->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame_4, 0, 2, 1, 1);

        frame_6 = new QFrame(centralWidget);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setFrameShape(QFrame::NoFrame);
        frame_6->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_6);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(1, 1, 1, 1);
        Warning_Label = new QLabel(frame_6);
        Warning_Label->setObjectName(QStringLiteral("Warning_Label"));
        QFont font;
        font.setFamily(QStringLiteral("Mukti Narrow"));
        font.setPointSize(14);
        font.setBold(false);
        font.setWeight(50);
        Warning_Label->setFont(font);
        Warning_Label->setFrameShape(QFrame::NoFrame);
        Warning_Label->setMidLineWidth(5);
        Warning_Label->setScaledContents(true);
        Warning_Label->setAlignment(Qt::AlignCenter);
        Warning_Label->setWordWrap(true);

        gridLayout_3->addWidget(Warning_Label, 0, 0, 1, 1);

        frame_3 = new QFrame(frame_6);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::NoFrame);
        frame_3->setFrameShadow(QFrame::Raised);

        gridLayout_3->addWidget(frame_3, 1, 0, 1, 1);


        gridLayout->addWidget(frame_6, 4, 2, 1, 1);

        LoginButton = new QPushButton(centralWidget);
        LoginButton->setObjectName(QStringLiteral("LoginButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(LoginButton->sizePolicy().hasHeightForWidth());
        LoginButton->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(LoginButton, 3, 2, 1, 1);

        UsernameBox = new QLineEdit(centralWidget);
        UsernameBox->setObjectName(QStringLiteral("UsernameBox"));
        sizePolicy1.setHeightForWidth(UsernameBox->sizePolicy().hasHeightForWidth());
        UsernameBox->setSizePolicy(sizePolicy1);
        UsernameBox->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(UsernameBox, 2, 2, 1, 1);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame, 0, 0, 1, 1);

        frame_7 = new QFrame(centralWidget);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setFrameShape(QFrame::NoFrame);
        frame_7->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame_7, 1, 2, 1, 1);

        Login->setCentralWidget(centralWidget);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", 0));
        RegisterButton->setText(QApplication::translate("Login", "Register", 0));
        Warning_Label->setText(QString());
        LoginButton->setText(QApplication::translate("Login", "Login", 0));
        UsernameBox->setText(QString());
        UsernameBox->setPlaceholderText(QApplication::translate("Login", "Enter Username", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
