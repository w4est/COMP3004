/********************************************************************************
** Form generated from reading UI file 'projectframe.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTFRAME_H
#define UI_PROJECTFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_projectFrame
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *Slider_value;
    QSlider *horizontalSlider;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer;

    void setupUi(QFrame *projectFrame)
    {
        if (projectFrame->objectName().isEmpty())
            projectFrame->setObjectName(QStringLiteral("projectFrame"));
        projectFrame->resize(400, 83);
        projectFrame->setFrameShape(QFrame::StyledPanel);
        projectFrame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(projectFrame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(projectFrame);
        label->setObjectName(QStringLiteral("label"));
        label->setWordWrap(true);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        Slider_value = new QLabel(projectFrame);
        Slider_value->setObjectName(QStringLiteral("Slider_value"));
        Slider_value->setMinimumSize(QSize(70, 0));
        Slider_value->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(Slider_value, 2, 2, 1, 1);

        horizontalSlider = new QSlider(projectFrame);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setStyleSheet(QLatin1String("QSlider::sub-page:horizontal {\n"
"background: white;\n"
"border: 1px solid #777;\n"
"height: 7px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: white;\n"
"border: 1px solid #777;\n"
"height: 7px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #f00);\n"
"border: 1px solid #777;\n"
"width: 7px;\n"
"margin-top: -6px;\n"
"margin-bottom: -6px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"background: white;\n"
"height: 10px;\n"
"}"));
        horizontalSlider->setMinimum(-7);
        horizontalSlider->setMaximum(6);
        horizontalSlider->setPageStep(1);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 2, 0, 1, 1);

        checkBox = new QCheckBox(projectFrame);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setMinimumSize(QSize(20, 20));
        checkBox->setMaximumSize(QSize(20, 20));
        checkBox->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkBox, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(15, 5, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);


        retranslateUi(projectFrame);

        QMetaObject::connectSlotsByName(projectFrame);
    } // setupUi

    void retranslateUi(QFrame *projectFrame)
    {
        projectFrame->setWindowTitle(QApplication::translate("projectFrame", "Frame", 0));
        label->setText(QString());
        Slider_value->setText(QString());
        checkBox->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class projectFrame: public Ui_projectFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTFRAME_H
