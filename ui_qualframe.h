/********************************************************************************
** Form generated from reading UI file 'qualframe.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUALFRAME_H
#define UI_QUALFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QualFrame
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *qual_id;
    QLabel *QualDescription;
    QFrame *qualInput;
    QGridLayout *gridLayout;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QLabel *Left_label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *Center_Label;
    QSpacerItem *horizontalSpacer_3;
    QLabel *Right_Label;
    QSlider *horizontalSlider;
    QSpacerItem *horizontalSpacer;

    void setupUi(QFrame *QualFrame)
    {
        if (QualFrame->objectName().isEmpty())
            QualFrame->setObjectName(QStringLiteral("QualFrame"));
        QualFrame->resize(800, 250);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QualFrame->sizePolicy().hasHeightForWidth());
        QualFrame->setSizePolicy(sizePolicy);
        QualFrame->setMinimumSize(QSize(800, 250));
        QualFrame->setFrameShape(QFrame::Box);
        QualFrame->setFrameShadow(QFrame::Plain);
        QualFrame->setLineWidth(2);
        QualFrame->setMidLineWidth(0);
        verticalLayout = new QVBoxLayout(QualFrame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        qual_id = new QLabel(QualFrame);
        qual_id->setObjectName(QStringLiteral("qual_id"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        qual_id->setFont(font);

        verticalLayout->addWidget(qual_id);

        QualDescription = new QLabel(QualFrame);
        QualDescription->setObjectName(QStringLiteral("QualDescription"));
        sizePolicy.setHeightForWidth(QualDescription->sizePolicy().hasHeightForWidth());
        QualDescription->setSizePolicy(sizePolicy);
        QualDescription->setMinimumSize(QSize(0, 80));
        QualDescription->setFrameShape(QFrame::Box);
        QualDescription->setFrameShadow(QFrame::Sunken);
        QualDescription->setAlignment(Qt::AlignCenter);
        QualDescription->setWordWrap(true);
        QualDescription->setMargin(2);

        verticalLayout->addWidget(QualDescription);

        qualInput = new QFrame(QualFrame);
        qualInput->setObjectName(QStringLiteral("qualInput"));
        sizePolicy.setHeightForWidth(qualInput->sizePolicy().hasHeightForWidth());
        qualInput->setSizePolicy(sizePolicy);
        qualInput->setMinimumSize(QSize(0, 60));
        qualInput->setFrameShape(QFrame::Box);
        qualInput->setFrameShadow(QFrame::Sunken);
        gridLayout = new QGridLayout(qualInput);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame_3 = new QFrame(qualInput);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setMinimumSize(QSize(0, 20));
        frame_3->setFrameShape(QFrame::NoFrame);
        frame_3->setFrameShadow(QFrame::Plain);
        horizontalLayout = new QHBoxLayout(frame_3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Left_label = new QLabel(frame_3);
        Left_label->setObjectName(QStringLiteral("Left_label"));

        horizontalLayout->addWidget(Left_label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        Center_Label = new QLabel(frame_3);
        Center_Label->setObjectName(QStringLiteral("Center_Label"));
        Center_Label->setLayoutDirection(Qt::LeftToRight);
        Center_Label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(Center_Label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        Right_Label = new QLabel(frame_3);
        Right_Label->setObjectName(QStringLiteral("Right_Label"));
        Right_Label->setLayoutDirection(Qt::RightToLeft);
        Right_Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(Right_Label);


        gridLayout->addWidget(frame_3, 2, 1, 1, 1);

        horizontalSlider = new QSlider(qualInput);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy1);
        horizontalSlider->setFocusPolicy(Qt::NoFocus);
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
        horizontalSlider->setMinimum(-5);
        horizontalSlider->setMaximum(5);
        horizontalSlider->setPageStep(1);
        horizontalSlider->setValue(0);
        horizontalSlider->setSliderPosition(0);
        horizontalSlider->setTracking(false);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setTickPosition(QSlider::TicksAbove);
        horizontalSlider->setTickInterval(1);

        gridLayout->addWidget(horizontalSlider, 3, 1, 1, 1);


        verticalLayout->addWidget(qualInput);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);


        retranslateUi(QualFrame);

        QMetaObject::connectSlotsByName(QualFrame);
    } // setupUi

    void retranslateUi(QFrame *QualFrame)
    {
        QualFrame->setWindowTitle(QApplication::translate("QualFrame", "Frame", 0));
        qual_id->setText(QApplication::translate("QualFrame", "TextLabel", 0));
        QualDescription->setText(QApplication::translate("QualFrame", "TextLabel", 0));
        Left_label->setText(QApplication::translate("QualFrame", "Least", 0));
        Center_Label->setText(QApplication::translate("QualFrame", "0", 0));
        Right_Label->setText(QApplication::translate("QualFrame", "Most", 0));
    } // retranslateUi

};

namespace Ui {
    class QualFrame: public Ui_QualFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUALFRAME_H
