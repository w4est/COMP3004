/********************************************************************************
** Form generated from reading UI file 'stuprojectframe.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUPROJECTFRAME_H
#define UI_STUPROJECTFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_stuProjectFrame
{
public:
    QLabel *label;

    void setupUi(QFrame *stuProjectFrame)
    {
        if (stuProjectFrame->objectName().isEmpty())
            stuProjectFrame->setObjectName(QStringLiteral("stuProjectFrame"));
        stuProjectFrame->resize(387, 52);
        stuProjectFrame->setFrameShape(QFrame::StyledPanel);
        stuProjectFrame->setFrameShadow(QFrame::Raised);
        label = new QLabel(stuProjectFrame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 358, 24));
        label->setWordWrap(true);

        retranslateUi(stuProjectFrame);

        QMetaObject::connectSlotsByName(stuProjectFrame);
    } // setupUi

    void retranslateUi(QFrame *stuProjectFrame)
    {
        stuProjectFrame->setWindowTitle(QApplication::translate("stuProjectFrame", "Frame", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class stuProjectFrame: public Ui_stuProjectFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUPROJECTFRAME_H
